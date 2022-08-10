#pragma once
#define WORD_SIZE 4
#define BYTE_SIZE 1
#define IMAGES_HEADER_SIZE 4
#define LABELS_HEADER_SIZE 2

static inline int big_to_little_endian(int num) {
    return ((num>>24)&0xff) | // move byte 3 to byte 0
                    ((num<<8)&0xff0000) | // move byte 1 to byte 2
                    ((num>>8)&0xff00) | // move byte 2 to byte 1
                    ((num<<24)&0xff000000); // byte 0 to byte 3
}

static inline uint8_t offset2D(uint8_t *arr, int x, int y, int xMax) {
    return arr[x * xMax + y];
}
static const char ASCII_COLOR[] = ".'`Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%%B@$";

void vector_to_image(int, int, int, FILE *);