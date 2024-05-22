#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Stwórz strukturę czlowiek która będzie zawierała poniższe pola:
    imie
    wiek
    zawod
    Stwórz funkcję zapisującą do pliku strukturę człowiek (nazwa pliku podana jako argument programu numer 2).
    Pod 1 argumentem podaj rodzaj operacji.
    Np: ODCZYT i ZAPIS
    A 2 argument tego programu to nazwa pliku na którym mamy wykonać tą operację.
    Stwórz funkcję odczytującą strukturę z pliku i zwracającą te dane jako strukturę.
    Stwórz funkcję wypisującą zawartość struktury w konsoli.
    Wywołaj ją po odczytaniu pliku.
*/

struct czlowiek {
    char* imie;
    int wiek;
    char* zawod;
};

int zapisz(char* name, struct czlowiek c) 
{
    FILE* uchwyt = fopen(name, "w");
    if (uchwyt == NULL) {
        printf("Cos nie tak\n");
        return -1;
    }

    char* buffer = malloc(1024);
    sprintf(buffer, "%s\n%d\n%s", c.imie, c.wiek, c.zawod);

    size_t ret = fwrite(buffer, 1, strlen(buffer), uchwyt);
    if (ret != strlen(buffer)) {
        printf("Cos nie tak\n");
        fclose(uchwyt);
        free(buffer);
        return -1;
    }

    printf("Git zapisane\n");
    fclose(uchwyt);
    free(buffer);
    return 1;
}

struct czlowiek odczytaj(char* name) 
{
    struct czlowiek c;
    FILE* uchwyt = fopen(name, "r");
    if (uchwyt == NULL) {
        printf("Cos nie tak\n");
        return c;
    }

    char* buffer = malloc(1024+1);
    size_t ret = fread(buffer, 1, 1024, uchwyt);

    if (ret>0) {
        buffer[ret] = 0x00;

        char* data = strtok(buffer, "\n");
        int counter = 0;

        while (data != NULL) {
            switch (counter) {
                case 0:
                    c.imie = strdup(data);
                    break;
                case 1:
                    c.wiek = atoi(data);
                    break;
                case 2:
                    c.zawod = strdup(data);
                    break;
            }
            data = strtok(NULL, "\n");
            counter++;
        }
    }

    free(buffer);
    fclose(uchwyt);
    return c;
}

void pokaz(struct czlowiek c)
{
    printf("Imie: %s\nWiek: %d\nZawod: %s\n", c.imie, c.wiek, c.zawod);
}

int main(int argc, char** argv)
{
    if (argc != 3) {
        printf("1 arg to rodzaj operacji (r lub w)\n2 arg to nazwa pliku");
        return -1;
    }

    switch(argv[1][0])
    {
        case 'r':
            struct czlowiek odczytany = odczytaj(argv[2]);
            pokaz(odczytany);
            free(odczytany.imie);
            free(odczytany.zawod);
            break;
        case 'w':
            struct czlowiek c;
            char* imie = "Pablo";
            char* zawod = "Rodzicow";

            c.imie = imie;
            c.wiek = 40;
            c.zawod = zawod;

            zapisz("g.txt", c);
            break;
    }

    return 0;
}