#include <stdio.h>
#include <stdlib.h>

/*
    Zapytaj użytkownika o 1 liczbę N.
    Po otrzymaniu tej liczby stwórz tablicę o rozmiarze tej liczby.
    Poproś użytkownika o wypełnienie tej tablicy (pytaj go po kolei o każdą zmienną).
    Użytkownik poda Ci N liczb całkowitych.
    Posortuj te liczby od największej do najmniejszej i je wypisz w tej kolejności.
*/

int read_positive_int(char* m) {
    int number;
    printf(m);
    while (scanf("%d", &number) != 1 || number <= 0) {
        while (getchar() != '\n');
        printf("Nieprawidlowa liczba.\n%s", m);
    }
    return number;
}

int read_int(char* m) {
    int number;
    printf(m);
    while (scanf("%d", &number) != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowa liczba.\n%s", m);
    }
    return number;
}

int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main(int argc, char** argv)
{
    int size = read_positive_int("Podaj rozmiar tablicy: ");
    int* arr = malloc(size*sizeof(int));

    if (arr == NULL) {
        printf("Cos nie tak.\n");
        return 1;
    }

    for (int i=0; i<size; i++) {
        char* message_buffer = malloc(1024);
        sprintf(message_buffer, "Podaj %d liczbę: ", i+1);
        int num = read_int(message_buffer);
        arr[i] = num;
        free(message_buffer);
    }

    qsort(arr, size, sizeof(int), compare_desc);

    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}