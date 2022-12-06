#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "math.h"


double ceil_dec(double number, int places);

int main (){

    double number;
    int places;
    double rounded;


    number = GetReal();
    places = GetInteger();


    rounded = ceil_dec(number,places);

    printf("%g",rounded);
    return 0;
}

double ceil_dec(double number, int places){

    double rounded;
    double decimal;
    double integer;

    //Diaxorismos akeraiou tmimatios apo dekadiko

    decimal = number-(int)number;
    integer = number-decimal;


    //Metakinisi epithimitou dekadikou meroys se akeraio gia epeksergasia
    decimal= decimal* pow(10.0,(float)places);
    decimal = ceil(decimal)/pow(10.0,(float)places);

    rounded = integer+decimal;




    return rounded;

}
