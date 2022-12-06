#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "math.h"


long Parag(int n);
double calculate_sinx(double rad);

int main(){



    int n;
    long parag;
    double rad;
    double sinx;

    printf("Dwse to x se aktinia: ");
    rad = GetReal();




    sinx= calculate_sinx(rad);

    printf("sinx: %12.10f",sinx);

    return 0;
}


long Parag(int n){
    int i;
    long sum;
    i = 0;
    sum = 1l;
    while(i<n){

        sum*=i+1;


        i++;
    }
    return sum;
}

double calculate_sinx(double rad){

    double sinx, temp;
    int n,i;
    n = 1;
    i =1;
    sinx = 0;
    temp = 1;
    while(n<=11 && fabs(temp) >=0.0001){

    temp = i*(pow(rad,n)/Parag(n));
    sinx += temp;

    n +=2;
    i *= -1;
    }
    printf("n: %d\n",n-2);
    return sinx;



}


