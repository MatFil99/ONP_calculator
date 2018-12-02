#ifndef CALCULATE_H_INCLUDED
#define CALCULATE_H_INCLUDED

void calculator( void );
void manage( void );
int sum(int a, int b);
int sub(int a, int b);
int prod(int a, int b);
int divide(int a, int b);
int rest(int a, int b);
void operate( int tab[], int* k, char line[], int* i );

#endif // CALCULATE_H_INCLUDED
