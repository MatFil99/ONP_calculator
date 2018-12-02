#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "Bufor.h"



bool ifDigital( char a ){
    if( a<58 && a>47) return true;
    else return false;
}

bool ifSign( char sign ){
    if( sign=='+' || sign=='-' || sign=='*' || sign=='/' || sign=='%' || sign==' ' || sign=='=' || sign=='\n'){
        return true;
    }else{
        return false;
    }
}

void getDigital( char assist[], int* j, char line[], int* i ){
    assist[*j]=line[*i];
    *j+=1;
}

void changeToNumber( int table[], char assist[], int* j, int* k ){
    table[*k]=atoi(assist);
    memset(assist, ' ', *j);
    *j=0;
    *k+=1;
}

void getLine( char line[]){
    int i=0;
    while(i==0 || line[i-1]!='='){
        scanf("%c", &line[i]);
        if(!ifDigital( line[i] ) && !ifSign( line[i] )){
            puts("Podano zly znak!");
            line[i]='=';
            line[0]='=';
        }
        ++i;
    }
}

void clearBuf( void ){
    char c;
    do{
        c=getchar();
    }while(c!='\n');
}
