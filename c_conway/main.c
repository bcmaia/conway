#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

// Function to set terminal attributes to raw mode
void set_raw_mode(struct termios *original_termios) {
    struct termios raw;
    tcgetattr(STDIN_FILENO, original_termios);
    raw = *original_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// Function to restore original terminal attributes
void restore_terminal(struct termios *original_termios) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, original_termios);
}

typedef struct {
	char* matrix;
	size_t height, width;
} board;

#define SUCCESS (0)
#define FAILURE (8)

int board_init (board* b, int height, int width) {
	b->height = (size_t)height;
	b->width = (size_t)width;
	b->matrix = (char*)calloc(sizeof(char), b->height * b->width);
	if (!b->matrix) return FAILURE;
	return SUCCESS;
} 

void board_del (board* b) {
	free(b->matrix);
}

void board_set(size_t height, size_t width, char val) {
	b->
}

int main() {
    struct termios original_termios;

    // Save current terminal state
    set_raw_mode(&original_termios);

    // Clear the terminal
    system("clear");

    char ch;
    int x, y;

    // Ask the user to input a character
    printf("Enter a character: ");
    ch = getchar();

    // Ask the user for coordinates
    printf("Enter X coordinate: ");
    scanf("%d", &x);
    printf("Enter Y coordinate: ");
    scanf("%d", &y);

    // Write the character at the given coordinates
    printf("\033[%d;%dH%c", y, x, ch);

    // Ask the user to type any key to finish the program
    printf("\nPress any key to finish the program.");
    getchar(); // Consume the newline character from the previous input
    getchar(); // Wait for user input

    // Close and restore the terminal to its previous state
    restore_terminal(&original_termios);

    return 0;
}

