
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"




int main(){

    long devices;
    int i =0;
    int boxes_label[]={1,5,20,50};
    long boxes[]={0,0,0,0};

    printf("Dwse plithos syskeuwn: ");
    devices = GetInteger();


    while (devices>=50){


    boxes[3] += 1;
    devices -= 50;

    }

    while (devices>=20){

    boxes[2] += 1;
    devices -= 20;

    }

    while (devices>=5){

    boxes[1] += 1;
    devices -= 5;

    }

    while (devices>=1){

    boxes[0] += 1;
    devices -= 1;

    }

    for (i=0;i<4;i++){
    printf("%2d%5d\n",boxes_label[i],boxes[i]);
    }

    return 0;
}
