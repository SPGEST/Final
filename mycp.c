#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *src, *dst;
    char ch;

    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    src = fopen(argv[1], "r");
    if (!src) {
        perror("Error opening source file");
        return 2;
    }

    dst = fopen(argv[2], "w");
    if (!dst) {
        perror("Error opening destination file");
        fclose(src);
        return 3;
    }

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dst);
    }

    fclose(src);
    fclose(dst);

    printf("Copy successful.\n");

    return 0;
}
