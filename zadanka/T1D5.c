#include <stdio.h>
#include <stdlib.h>

/*
 T1D5 - Pamiętaj bo pamięć to rzecz święta xD (pzdr bonusrpk)
 Zarządzanie pamięcią - utrwalenie
 22.05.2025
 
 
 Postępuj zgodnie z instrukcjami w komentarzach, i dopisz brakujący kod.
 Zwróć uwagę na użycie funkcji calloc i free.
 Zastanów się, dlaczego używamy calloc zamiast malloc.
 */

int read_int(char* m) {
    int number;
    printf(m);
    while (scanf("%d", &number) != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowa liczba.\n%s", m);
    }
    return number;
}


int main(void) {
    // Zadanie 1: Poproś użytkownika o podanie liczby elementów
    int n;
    printf("Podaj liczbe elementow: ");
    scanf("%d", &n);

    if (n<=0) return -1;

    // Zadanie 2: Przydziel pamięć dynamicznie dla 'n' elementów używając calloc
    int* arr = calloc(n, sizeof *arr);

    // Zadanie 3: Sprawdź, czy pamięć została pomyślnie przydzielona
    if (!arr) {
        printf("Pamięć nie została pomyślnie przydzielona\n");
        return -1;
    }

    // Zadanie 4: Wprowadź elementy do przydzielonej pamięci
    for (int i=0; i<n; i++) {
        char* message_buffer = malloc(1024);
        sprintf(message_buffer, "Podaj %d liczbę: ", i+1);
        int num = read_int(message_buffer);
        arr[i] = num;
        free(message_buffer);
    }
    

    // Zadanie 5: Wyświetl te elementy
    printf("Twoje elementy: \n");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Zadanie 6: Zwolnij przydzieloną pamięć
    free(arr);
    return 0;
}