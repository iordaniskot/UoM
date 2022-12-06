#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int add(int x , int y);
int sub(int x , int y);
int mult(int x , int y);
int divd(int x, int y);


int main (){

    int x,y;
    int addn,subn,multn,divdn,exp1n,exp2n;



    printf("Dwse ton 1o arithmo: ");
    x = GetInteger();
    printf("Dwse ton 2o arithmo: ");
    y = GetInteger();

    addn = add(x,y);
    subn = sub(x,y);
    multn = mult(x,y);
    divdn = divd(x,y);
    exp1n = mult(addn,sub(y,divdn));
    exp2n = divd(sub(multn,x),addn);


    printf("add: %d", addn);
    printf("\nsub: %d",subn);
    printf("\nmult: %d",multn);
    printf("\ndivd: %d",divdn);
    printf("\nexp1: %d",exp1n);
    printf("\nexp2: %d",exp2n);





    return 0;
}

int add(int x, int y){

    return x+y;
}

int sub (int x , int y){

    return x-y;
}

int mult(int x , int y){

    return x*y;
}

int divd(int x, int y){

    return x/y;
}
