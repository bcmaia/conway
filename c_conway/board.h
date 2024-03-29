#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "utils.h"

typedef struct {
	char* matrix;
	char* aux;
	uint32_t height;
	uint32_t width; 
	uint64_t length;
} board_t;

int board_init (board_t* b, uint32_t width, uint32_t height);
void board_del (board_t* b);

void board_tick (board_t* b);
void board_print(
	const board_t* b, 
	const uint32_t cam_x,
	const uint32_t cam_y,
	const uint16_t term_width, 
	const uint16_t term_height
);

#endif 