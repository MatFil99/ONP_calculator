#include <stdio.h>

#include "Interface.h"

void welcome( void ){
    puts("\tWitaj w kalkulatorze!");
    puts("Obslugiwane operacje:\n- dodawanie\n- odejmowanie\n- mnozenie\n- dzielenie\n- reszta z dzielenia");
}

void instruction( void ){
    puts("\n\tINSTRUKCJA:\nAby wykonac operacje podaj po spacji ciag liczb i znakow dzialania");
    puts("dodawanie ( + )\t odejmowanie ( - )\nmnozenie ( * )\t dzielenie ( / )\nreszta z dzielenia ( % )");
    puts("Aby zakonczyc prace programu wpisz z");
    puts("Na koncu operacji podaj znak = \n\tPRZYKLAD:\t2 3 + 5 * = <==>  (2+3)*5=");
}
