#include <stdio.h>
#include <stdlib.h>

/*
    Przyjmij 3 parametry (może to być albo argument programu albo możesz odczytać 3 zmienne z inputu użytkownika).
    1 parametr to liczba całkowita
    2 parametr to jeden z tych znaków: * / + -
    3 parametr to liczba całkowita
    Wykonaj operację matematyczną która powstanie z tych zmiennych i wypisz jej rezultat na ekranie.
*/

int licz(int a, char o, int b) {
    switch (o) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case 'x':
            return a * b;
        case '/':
            if (b == 0) 
            {
                printf("aha przez 0?\n");
                return -1;
            }
            return a / b;
        default:
            printf("hmm?\n");
            return -1;
    }
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Podaj wszystkie argumenty\n");
        return -1;
    }

    int ret = licz(atoi(argv[1]), argv[2][0], atoi(argv[3]));

    printf("%s %s %s = %d\n", argv[1], argv[2], argv[3], ret);
    return 0;
}