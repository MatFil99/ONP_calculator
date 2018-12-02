#include <stdio.h>
#include <stdlib.h>

#include "Interface.h"
#include "Calculate.h"
#include "Bufor.h"

void calculator( void ){
        char assist[11]={};
        char line[100]={};
        int table[30];
        int i=0; // index of table - line
        int j=0; // index of table - assist
        int k=0; // index of table - table
        int counterNumber=0; // count numbers
        int counterSign=0; // count characters
        getLine( line );
        while(line[i]!='='){
            if(ifDigital( line[i]) || (line[i]=='-' && ifDigital(line[i+1]))){
                getDigital( assist , &j, line , &i );
            }else if( i>0 && ifDigital(line[i-1]) && (line[i]==' ' || line[i]=='\n') ){
                changeToNumber( table, assist, &j, &k );
                ++counterNumber;
            }else if(ifSign(line[i]) && line[i]!=' ' && line[i]!='\n'&& k>=2 ){
                operate( table, &k, line, &i );
                ++counterSign;
            }else if(ifSign(line[i]) && line[i]!=' ' && line[i]!='\n' && k<2){
                puts("Bledne dzialanie!");
                line[i+1]='=';
                k=0;
            }
            ++i;
        }
        if(k==1){
            printf("%d\n", table[0]);
        }else if(counterNumber>counterSign+1){
            puts("Bledne dzialanie!");
        }else{}
        manage();
}

void manage( void ){
    char man='0';
    puts("Aby wyswietlic instrukcje wpisz i\nAby zakonczyc prace wpisz z\nAby kontynuowac wpisz dowolny inny znak\n(Liczy sie pierwszy wpisany znak!)");
    clearBuf();
    scanf("%c", &man);
    clearBuf();
    if(man=='i'){
        system("cls");
        instruction();
        calculator();
    }else if(man=='z'){
    }else{
        system("cls");
        calculator();
    }
}

int sum(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

int prod(int a, int b){
    return a*b;
}

int divide(int a, int b){
    if(b!=0){
        return a/b;
    }else {
        puts("Nie mozna dzielic przez 0!");
        return 0;
    }
}

int rest(int a, int b){
    if(b!=0){
        return a%b;
    }else {
        puts("Nie mozna dzielic przez 0!");
        return 0;
    }
}

void operate( int tab[], int* k, char line[], int* i ){
    char sign=line[*i];
    *k-=1;
        switch(sign){
    case '+':
        tab[*k-1]=sum(tab[*k-1], tab[*k]);
        break;
    case '-':
        tab[*k-1]=sub(tab[*k-1], tab[*k]);
        break;
    case '*':
        tab[*k-1]=prod(tab[*k-1], tab[*k]);
        break;
    case '/':
        tab[*k-1]=divide(tab[*k-1], tab[*k]);
        break;
    case '%':
        tab[*k-1]=rest(tab[*k-1], tab[*k]);
        break;
    default:
        *k+=1;
        break;
        }
}
