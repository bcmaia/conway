#include "board.h"

int board_init (board_t* b, uint32_t width, uint32_t height) {
	b->height = (uint32_t)height;
	b->width = (uint32_t)width;
	b->length = ((uint64_t)b->height) * ((uint64_t)b->width);

	b->matrix = (char*)malloc(b->length * sizeof(char));
    b->aux = (char*)malloc(b->length * sizeof(char));

	for (uint64_t i = 0; i < b->length; i++) {
		char temp = (char)(!(rand() % 3));

		b->matrix[i] = temp;
		b->aux[i] = temp;
	}

	if (!(b->matrix && b->aux)) return 1;
	return 0;

} 

void board_del (board_t* b) {
	free(b->matrix);
	free(b->aux);
}

void board_tick (board_t* b) {
	printf("c");
	
	intptr_t length = b->length;

	for (uint64_t i = 0; i < b->length; i++) {
		intptr_t neighbor = (intptr_t) &(b->matrix[(i - 1 - b->width) % length]);
		

		char sum = !(rand() % 10000);
		sum += ((char*)neighbor)[0] + ((char*)neighbor)[1] + ((char*)neighbor)[2];
		neighbor = (intptr_t) &(b->matrix[(i - 1) % length]);
		sum += ((char*)neighbor)[0] + ((char*)neighbor)[2];
		neighbor = (intptr_t) &(b->matrix[(i - 1 + b->width) % length]);
		sum += ((char*)neighbor)[0] + ((char*)neighbor)[1] + ((char*)neighbor)[2];

		if (2 > sum || 3 < sum) b->aux[i] = 0;
		else if (3 == sum) b->aux[i] = 1; 
	}

	char* temp = b->matrix;
	b->matrix = b->aux;
	b->aux = temp;
}

void board_print(
	const board_t* b, 
	const uint32_t cam_x,
	const uint32_t cam_y,
	const uint16_t term_width, 
	const uint16_t term_height
) {
	system("clear");
	size_t length = b->height * b->width;

	uint16_t w = (uint16_t) MIN ((uint64_t)term_width, b->width);
	uint16_t h = (uint16_t) MIN ((uint64_t)term_height, b->height);

	for (uint16_t i = 0; i < h; i++) printat(1, i, 'X');
	for (uint16_t i = 0; i < w; i++) printat(i, 1, 'X');

	uint16_t temp = w - 1;
	for (uint16_t i = 0; i < h; i++) printat(temp, i, 'X');

	temp = term_height - 1;
	for (uint16_t i = 0; i < w; i++) printat(i, temp, 'X');

	for (uint16_t y = 2; y < h - 2; y++) {
		for  (int16_t x = 2; x < w - 2; x++) {
			uint64_t i = (y - 2 + cam_y) * b->width + x - 2 + cam_x;
			char c = b->matrix[i] ? 'O' : ' ';
			printat(x, y, c);
		}
	}
}
