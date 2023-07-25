#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include <time.h>


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


int main(int argc, char* argv[]) {
    srand(time(NULL));

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

    board_t board;
    flag = board_init(&board, width, height);

    if (flag) {
        printf("[ERROR] Failed to initialize board.\n");
        return EXIT_FAILURE;
    }

    bool active = true;

    while (active) {
        printf("a\n");
        board_tick(&board);
        printf("b\n");
        board_print(&board);
        usleep(250 * 1000);
    }

    board_del(&board);

    return EXIT_SUCCESS;
}

