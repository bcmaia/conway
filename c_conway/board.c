#include "board.h"

int board_init (board_t* b, uint32_t width, uint32_t height) {
	b->height = (uint32_t)height;
	b->width = (uint32_t)width;
	b->length = ((uint64_t)b->height) * ((uint64_t)b->width);

	b->matrix = (char*)malloc(b->length * sizeof(char));
    b->aux = (char*)malloc(b->length * sizeof(char));

	for (uint64_t i = 0; i < b->length; i++) {
		char temp = (char)(!(rand() % 20));

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
	b->aux = b->matrix;
}

void board_print(board_t* b) {
	system("clear");
	size_t length = b->height * b->width;

	for (size_t i = 0; i < length; i++) {
		if (0 == (i % b->width)) printf("\n");
		printf("%c", b->matrix[i] ? 'O' : ' ');
	}
	printf("\n");
}
