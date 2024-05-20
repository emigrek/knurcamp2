#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    Poproś użytkownika o podanie 2 stringów.
    Połącz te 2 stringi ze sobą i zapisz je do pliku dupa.txt.
*/

int main(int argc, char** argv)
{
    if (argc != 3) {
        printf("Podaj dwa stringi\n");
        return -1;
    }

    char* buffer = malloc(1024);
    sprintf(buffer, "%s %s", argv[1], argv[2]);

    FILE* uchwyt = fopen("dupa.txt", "w");
    if (uchwyt == NULL) {
        printf("hmm\n");
        return -1;
    }

    size_t ret = fwrite(buffer, 1, strlen(buffer), uchwyt);
    if (ret == strlen(buffer)) {
        printf("git zapisane\n");
    }

    free(buffer);
    fclose(uchwyt);
    return 0;
}