#include <stdio.h>
#include <stdlib.h>

/*
 T1D6
 BOMBELKOWE SORTOWANIE NA WSKAZNIKACH HEHE
 Powodzenia bombelku, napisz ciało funkcji sortujPrzezWskazniki.
 Aby spełniała swoje zadanie i posortowała liczby rosnąco.
 */

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;  
}

void sortujPrzezWskazniki(int *tab, int rozmiar) {
    // miejsce na rozwiązanie
    for(int i=0; i<rozmiar; i++)
		for(int j=1; j<rozmiar-i; j++)
		    if(tab[j-1] > tab[j])
			    swap(&tab[j-1], &tab[j]);
}


int main() {
    int liczby[] = {34, 67, 23, 28, 98, 15};
    int rozmiar = sizeof(liczby) / sizeof(liczby[0]);

    printf("Tablica przed sortowaniem: \n");
    for (int i = 0; i < rozmiar; i++) {
        printf("%d ", liczby[i]);
    }
    printf("\n");

    sortujPrzezWskazniki(liczby, rozmiar);

    printf("Tablica po sortowaniu: \n");
    for (int i = 0; i < rozmiar; i++) {
        printf("%d ", liczby[i]);
    }
    printf("\n");

    return 0;
}