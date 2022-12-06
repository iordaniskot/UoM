#include <stdio.h>
#include "simpio.h"
#include "genlib.h"


int main(){

    float dt,df;
    float kathara_tm,meikta_tm;

    printf("Dos kathara tm: ");
    kathara_tm = GetReal();
    printf("Dos meikta tm: ");
    meikta_tm = GetReal();

    dt= (kathara_tm*1.33*61)/365.0;
    df = (meikta_tm*0.13*61)/365.0  ;

    printf ("DT: %.2f\nDF: %.2f",dt,df);


    return 0;
}
