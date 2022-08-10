#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include <fcntl.h>

#include "vector_to_image.h"

void vector_to_image(int num_img, int rows, int columns, FILE *input_file) {
    uint8_t pixels[rows * columns];
    int return_pos = ftell(input_file);
    fseek(input_file, num_img * rows * columns, SEEK_CUR);
    int bytes_to_read = rows * columns;
    while (bytes_to_read) {
        bytes_to_read -= fread(pixels, BYTE_SIZE, bytes_to_read, input_file);
    }
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            printf("%c ", ASCII_COLOR[offset2D(pixels, row, col, rows) / 4]);
        }
        printf("\n");
    }
    fseek(input_file, return_pos, SEEK_SET);
}
