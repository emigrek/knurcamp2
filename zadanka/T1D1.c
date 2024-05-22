/* NIE DOTYKAJ */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void weryfikacja1(void* ss, int sz)
{
    char* st = (char*)ss; // Konwersja pozwalajaca na dostep do surowych bajtow
    int wiek = *st; // Odczytanie wartosci pod adresem st, na tym etapie st wskazuje na poczatek struktury czyli wiek
    if(wiek != 105) // Walidacja
    {
        printf("Błędne rozwiązanie\n");
        return;
    }
    st += sz / 3; // Przesuniecie wskaznika do nastepnej danej w strukturze
    uint64_t imiePtr = (*(uint64_t*)st);
    char* imie = (char*)imiePtr;
    st += sz / 3; // Przesuniecie wskaznika do nastepnej danej w strukturze

    if(strcmp(imie, "Jan") != 0) // Walidacja
    {
        printf("Błędne rozwiązanie\n");
        return;
    }
    float wzrost = *(float*)st;
    if(wzrost < 2.138 && wzrost > 2.136) // Walidacja
    {
        printf("Brawo poprawne rozwiązanie\n");
    }
    else
    {
        printf("Ups, błędne rozwiązanie\n");
    }
}
/* KONIEC SEKCJI NIE DOTYKAJ */

/*
 Treść zadania:
 
 Stwórz strukturę o nazwie `czlowiek`.
 Zrób żeby zawierała następujące pola:
 - `wiek` <- liczba całkowita (rozmiar standardowy)
 - `imie` <- no jego imie a co xD (ptr do stringa)
 - `wzrost` <- liczba zmiennoprzecinkowa w metrach amerykańskich np 1.234
 
 Stwórz człowieka o imieniu `Jan`, wieku 105 lat, wzroście 2 m 137 cm (w metrach amerykańskich - 1 metr = 1000 cm - 2m 137cm = 2.137)
 Pola wiek, imie, i wzrost muszą mieć taką samą koleność.
 
 Uruchom funckje `weryfikacja1` ze swojej funkcji main podając wskaźnik do człowieka oraz rozmiar struktury człowiek jako drugi parametr.
 
 ***** Zadanie na 6 albo gwiazdke jak zwał tak zwał *****
 Opisz co robi po kolei funckja `void weryfikacja1(void* ss, int sz)`
*/

struct czlowiek {
    int wiek;
    char* imie;
    float wzrost;
};

int main(void)
{
    // Miejce na twój kod
    struct czlowiek c;
    char* imie = "Jan";

    c.wiek = 105;
    c.imie = imie;
    c.wzrost = 2.137;

    weryfikacja1(&c, sizeof(c));
}