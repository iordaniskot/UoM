#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


int main (){


    float epidoma;
    int paidia;
    int misthos;

    printf("Dwse vasiko mistho: ");
    misthos = GetInteger();
    printf("Dwse arithmo paidion: ");
    paidia = GetInteger();

    epidoma = misthos;


    switch(paidia){
        case 0:
            epidoma = 0;
            break;
        case 1:
            epidoma *= 0.04;
            break;
        case 2:
            epidoma *= 0.09;
            break;
        case 3:
            epidoma *=0.15;
            break;
        default:
            epidoma*=(0.15+(paidia-3)*0.04);
            break;
    }

    printf("Epidoma: %.2f",epidoma);




    return 0;
}
