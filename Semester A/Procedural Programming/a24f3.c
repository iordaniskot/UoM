#include <stdio.h>
#include "genlib.h"
#include "simpio.h"




int main (){
    int height,width,i,j;


    printf("Dose ypsos: ");
    height = GetInteger();

    printf("Dose platos: ");
    width = GetInteger();

    for (i = 0; i<width;i++){

        printf("*");
    }

    for (i=0;i<height-2;i++){
        printf("\n*");

        for (j = 0; j<width-2;j++){

            printf(" ");
        }
        printf("*");
    }
    printf("\n");

     for (i = 0; i<width;i++){

        printf("*");
    }



    return 0;
}
