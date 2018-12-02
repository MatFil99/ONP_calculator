#ifndef LOADLINE_H_INCLUDED
#define LOADLINE_H_INCLUDED

#include <stdbool.h>

bool ifDigital( char a );
bool ifSign(char sign);
void getDigital( char assist[], int* j, char line[], int* i );
void changeToNumber( int table[], char assist[], int* j, int* k );
void getLine( char line[] );
void clearBuf( void );

#endif // LOADLINE_H_INCLUDED
