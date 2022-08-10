#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "vector_to_image.h"

int main() {
    FILE *mnist_training_images = NULL;
    const char *mnist_training_images_filename = "train-images-idx3-ubyte";
    mnist_training_images = fopen(mnist_training_images_filename, "rb");

    if (!mnist_training_images) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    uint32_t images_header_buffer[IMAGES_HEADER_SIZE];
    
    int bytes_read = fread(images_header_buffer, WORD_SIZE, IMAGES_HEADER_SIZE, mnist_training_images);
    uint32_t images_magic_num = big_to_little_endian(images_header_buffer[0]);
    uint32_t images_num_samples = big_to_little_endian(images_header_buffer[1]);
    uint32_t rows = big_to_little_endian(images_header_buffer[2]);
    uint32_t columns = big_to_little_endian(images_header_buffer[3]);

    for (int i = 0; i < images_num_samples; i++) {
        printf("\e[1;1H\e[2J");
        vector_to_image(i, rows, columns, mnist_training_images);
        usleep(100);
    }
    vector_to_image(5, rows, columns, mnist_training_images);
    fclose(mnist_training_images);
    
    return 0;
}