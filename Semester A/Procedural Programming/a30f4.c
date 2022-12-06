#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "math.h"

calc(int i, int j ,int k);

int main (){

    int i,j,k,n;
    int total = 0;

    printf("Dwse n: ");
    n = GetInteger();

    for (i = 1; i<4;i++){
        for (j=1; j<n+1;j++){
            for (k=1; k<n+1; k++){
                total += calc(i,j,k);
            }
        }
    }

    printf("Result: %d", total);



    return 0;
}


calc(int i ,int j, int k){

    if (i==1){
        return (j+k);
    }

    if (i==2){
        return (j-k);
    }

    return (floor((j+k)/2));

}
