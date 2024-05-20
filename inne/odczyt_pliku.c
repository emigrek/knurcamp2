#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    FILE* uchwyt = fopen("test.txt", "r");
    if (uchwyt == NULL) {
        printf("hmm\n");
        return -1;
    }

    char* buffer = malloc(1024+1);

    size_t ret = fread(buffer, 1, 1024, uchwyt);

    if (ret>0) {
        buffer[ret] = 0x00;

        printf("Z pliku: %s\n", buffer);
    }

    free(buffer);
    fclose(uchwyt);

    return 0;
}