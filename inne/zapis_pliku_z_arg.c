#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    if (argc != 2) {
        printf("Podaj nazwe pliku jako argument\n");
        return -1;
    }
    
    const char* wiadomosc = "MUSZE MIEC LEPSZA WIADOMOSC\n";

    FILE* uchwyt = fopen(argv[1], "w");
    if (uchwyt == NULL) {
        printf("hmm\n");
        return -1;
    }

    size_t ret = fwrite(wiadomosc, 1, strlen(wiadomosc), uchwyt);
    if (ret == strlen(wiadomosc)) {
        printf("git zapisane\n");
    }

    fclose(uchwyt);
    return 0;
}