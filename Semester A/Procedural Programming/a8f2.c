
#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
#include "simpio.h"


int main (){


    int estimated_time;
    int real_time;
    int difference;
    int acceptable;



    printf("Dose problepomeno xrono:");
    estimated_time = GetInteger();
    printf("Dose pragmatiko xrono:");
    real_time = GetInteger();


    difference = estimated_time - real_time;

    if (estimated_time<=29){

        acceptable = 1;
    }
    else if (estimated_time <=59){
        acceptable = 2;
    }
    else if (estimated_time <=89){
        acceptable = 3;
    }
    else if (estimated_time <=119){
        acceptable = 4;
    }
    else if (estimated_time <=179){
        acceptable = 6;
    }
    else if (estimated_time <=239){
        acceptable = 8;
    }
    else if (estimated_time <=359){
        acceptable = 13;
    }
    else{
        acceptable = 17;
    }

    printf("Apodekth diafora: %d\n",acceptable);
    printf("Diafora eisodou: %d\n",difference);


    if (acceptable >= difference && -1*acceptable <= difference){

        printf("GOOD");
    }
    else if(acceptable<difference){
        printf("BIG");
    }
    else{
        printf("SMALL");
    }







    return 0;
}
