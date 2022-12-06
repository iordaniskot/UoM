#include <stdio.h>
#include "genlib.h"



int main (){

    int i;

    for (i = 1; i<101; i++){

        if(i<10){
        printf("   %d",i);
        }
        else if(i<100){
            printf("  %d",i);

        }
        else{
            printf(" %d",i);
        }
        if (i%10 == 0){
            printf("\n");
        }

    }

    return 0;
}
