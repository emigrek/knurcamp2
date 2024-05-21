#include <stdio.h>
#include <stdbool.h>

/*
 Zaimplementuj ciało funkcji isPrime która zwróci true jeśli podany int §num§ jest liczba pierwszą.
 Zwróć false w przeciwnym wypadku.
 */

bool isPrime(int num) {
    if (num < 2)
        return false;

    for (int i = 2; i <= num / 2; ++i)
        if (num % i == 0) 
            return false;

    return true;
}

// Funkcja przyjmujaca nic i zwracajaca nic ktora sprawdza czy isPrime zwraca poprawny boolean przez sprytny ternary operator i konkatenacje stringow
void selfTest(void) {
    printf("Self-checking code:\n");
    printf("Test 1: %s\n", isPrime(2) ? "POPRAWNY" : "NIEPRAWIDŁOWY");
    printf("Test 2: %s\n", isPrime(11) ? "POPRAWNY" : "NIEPRAWIDŁOWY");
    printf("Test 3: %s\n", isPrime(99) ?  "NIEPRAWIDŁOWY" : "POPRAWNY");
    printf("Test 4: %s\n", isPrime(97) ? "POPRAWNY" : "NIEPRAWIDŁOWY");
}

int main(void) {
    int num;
    printf("Podaj liczbe: ");
    scanf("%d", &num); // Pobranie liczby do int num;

    if (isPrime(num)) { // Check na podanej liczbie
        printf("%d jest liczba pierwsza.\n", num);
    } else {
        printf("%d nie jest liczba pierwsza.\n", num);
    }

    // Call funkcji sprawdzajacej czy isPrime dziala przy innych argumentach num
    // Run the self-checking code
    selfTest();

    return 0;
}