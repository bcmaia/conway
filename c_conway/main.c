#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>

#include "utils.h"
#include "board.h"

// const uint32_t CHUNK_SIZE = 4;

// typedef struct {
//     board_t* b;
//     uint32_t x;
//     uint32_t y;
// } thread_data_t;

// void* runner (void* arg) {
//     thread_data_t* data = (thread_data_t*)arg;

//     if (
//         (data->x >= data->b->width) 
//         || (data->y >= data->b->height)
//     ) return NULL;
    
//     uint32_t sum = 0;

//     for  
// }

bool active = true;

// Signal handler function for SIGINT (Ctrl+C)
void sigintHandler(int signum) {
    //printf("\nCtrl+C (SIGINT) received. Exiting...\n");
    active = false;
}

int main(int argc, char* argv[]) {
    // Save current terminal state
    struct termios original_termios;
    set_non_blocking_mode(&original_termios);
 
    srand(time(NULL));

    // Register the signal handler for SIGINT
    if (signal(SIGINT, sigintHandler) == SIG_ERR) {
        printf("Unable to register signal handler for SIGINT.\n");
        return 1;
    }

    int flag = 1;
    uint32_t width = 30;
    uint32_t height = 30;
    
    switch (argc)
    {
        case 1: break;
        case 2:
            flag = sscanf(argv[0], " %u", &width);
            break;
        case 3:
            flag = sscanf(argv[0], " %u %u", &width, &height);
            break;
        default:
            printf("[ERROR] Too many parameters!\n");
            return EXIT_FAILURE;
    }

    if (0 >= flag) {
        printf("[ERROR] Failed to read parameters.\n");
        return EXIT_FAILURE;
    }

    //uint64_t max = MAX(width, height);

    uint16_t term_width = get_term_width();
    uint16_t term_height = get_term_height();

    board_t board;
    if (active) flag = board_init(&board, width, height);

    if (flag) {
        printf("[ERROR] Failed to initialize board.\n");
        return EXIT_FAILURE;
    }

    struct termios orig_termios, new_termios;
    
    // Save the original terminal settings
    tcgetattr(STDIN_FILENO, &orig_termios);
    
    // Set the terminal into non-canonical (raw) mode
    new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

    //active = true;

    int flags = fcntl(STDIN_FILENO, F_GETFL);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK); // Set non-blocking for stdin

    while (active) {
        printf("a\n");
        board_tick(&board);
        printf("b\n");
        board_print(&board, 0, 0, term_width, term_height);
        usleep(250 * 1000);
    }

    // Restore the original terminal settings before exiting
    restore_terminal_attributes(&original_termios);
    board_del(&board);

    return EXIT_SUCCESS;
}

