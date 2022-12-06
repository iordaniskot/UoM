#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "math.h"


int main (){


    int code,members;
    long collection,budget;

    budget = -20000;





    do{
        printf("Dwse kwdiko: ");
        code = GetInteger();
        while (code != 1 && code != 2){

            printf("Lathos!\n");
            printf("Dwse kwdiko: ");
            code = GetInteger();

        }
        if (code == 1){

        printf("Dwse arithmo atomwn: ");
        members = GetInteger();

        collection = 350*members;
        if (members >10){

        collection -= 35*members;

        }
        budget += collection;
        printf("Kostos: %d\n",collection);
        }


    }while (code == 1);

    printf("Kerdos:%d",budget);









    return 0;

}
