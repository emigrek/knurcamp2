#include <stdio.h>
#include <stdlib.h>

/*
    Poproś użytkownika o podanie 1 liczby całkowitej N.
    Wypisz ciąg fibonacziego do liczby N. 
*/

void wypiszFib(int n) {
    int l1 = 0;
    int l2 = 1;
    int next = 0;

    printf("%d, %d, ", l1, l2);
    next = l1 + l2;

    while (next <= n) {
        printf("%d, ", next);
        l1 = l2;
        l2 = next;
        next = l1 + l2;
    }

    printf("\n");
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Podaj wszystkie argumenty\n");
        return -1;
    }
    printf("uwaga podaje do %d:\n", atoi(argv[1]));
    wypiszFib(atoi(argv[1]));
}