#include "utils.h"


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

int printat (int x, int y, char c) {
	return printf("\033[%d;%dH%c", y, x, c);
}


// Function to get the height and width of the terminal
unsigned short get_term_height() {
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    return (unsigned short) ws.ws_row;
}

// Function to get the height and width of the terminal
unsigned short get_term_width() {
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    return (unsigned short) ws.ws_col;
}

