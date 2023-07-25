#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define SUCCESS (0)
#define FAILURE (1) 

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Function to set terminal attributes to raw mode
void set_raw_mode(struct termios *original_termios);
void restore_terminal(struct termios *original_termios);
int printat (int x, int y, char c);
unsigned short get_term_height();
unsigned short get_term_width();

#endif // !1