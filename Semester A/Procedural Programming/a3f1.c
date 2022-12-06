#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main ()
{
    int siskeves;
    int peninta,eikosi,pente,ena;

    siskeves=0;
    peninta = 0;
    eikosi = 0;
    pente = 0 ;
    ena = 0;


    siskeves = GetInteger();

    printf("Dose plithos syskeuwn:");
    while (siskeves>=50){


    peninta += 1;
    siskeves -= 50;

    }

    while (siskeves>=20){

    eikosi += 1;
    siskeves -= 20;

    }

    while (siskeves>=5){

    pente += 1;
    siskeves -= 5;

    }

    while (siskeves>=1){

    ena += 1;
    siskeves -= 1;

    }

    printf("50 %d \n 20 %d \n 5 %d \n 1 %d",peninta,eikosi,pente,ena);


    return 0;
}
