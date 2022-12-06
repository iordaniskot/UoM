
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){

    int A[4], B[4], C[4][4],i,j,sum;

    sum = 0;

    for (i=0; i<4; i++){
        printf("Insert SetA num%d:",i);
        A[i] = GetInteger();
        sum += A[i];
    }

    for (i=0; i<4; i++){
        printf("Insert SetB num%d:",i);
        B[i] = GetInteger();
        sum += B[i];
    }


    printf("Sum: %d",sum);

    for (i=0; i<4; i++){
        for (j = 0; j<4; j++){

            C[i][j] = A[j] + B[i];

        }

    }

    for (i = 0; i<4 ; i++){
        printf("\n");
        for (j = 0; j<4; j++){
            printf("%6d",C[i][j]);
        }

    }





    return 0;
}
