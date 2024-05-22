#include <stdio.h>

// T1D4: Dziki i wskaźniki
// Zaimplementuj funkcję void swap(int *a, int *b) aby podmienić zawartość a na b i b na a.
// Zadanie bonusowe: Napisz funkcję, która przyjmuje wskaźnik do innej funkcji.
// Wywołaj z tej funkcji ten wskaźnik.
// Spraw aby funkcja pod wskaźnikiem wypisała na ekranie "SIGMA".

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;  
}

void function(void (*func)()) {
    func();
}

void sigma() {
    printf("SIGMA\n");
}

int main(void) {
    int x = 10;
    int y = 20;
    printf("Przed swapem: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("Po swapie: x = %d, y = %d\n", x, y);

    function(sigma);

    return 0;
}