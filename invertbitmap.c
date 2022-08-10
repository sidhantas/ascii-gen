#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Input format: ./inver8bitbitmap [file.bmp]");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", argv[1]);
    FILE *input_file = fopen(argv[1], "rb+");
    FILE *output_file = fopen("flipped_bits.bmp", "wb+");
    if (!input_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    if (!output_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    uint8_t headers[1162];
    fread(headers, 1, 1162, input_file);
    fwrite(headers, 1, 1162, output_file);
    uint8_t buf[1];
    while(fread(buf, 1, 1, input_file)) {
        printf("%2x", buf[0]);
        buf[0] = ~buf[0];
        printf(" %2x", buf[0]);
        fwrite(buf, 1, 1, output_file);
    }
    fclose(input_file);
    return 0;
}