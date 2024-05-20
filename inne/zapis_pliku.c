#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    const char* wiadomosc = "MUSZE MIEC LEPSZA WIADOMOSC\n";
    const char* plik_do_zapisu = "test.txt";

    FILE* uchwyt = fopen(plik_do_zapisu, "w");
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