#include <stdio.h>
#include "math.h"
#include "simpio.h"

void addBand(int index,int frequency[]);
void addFrequency(int index, int frequency[],float arrivals, float departures);
int maxFrequencyPos( int frequency[]);

int main(){

    int nbands;

    printf("Dwse plithos sygkrotimatwn: ");
    nbands = GetInteger();
    char bands[nbands][30];
    float departures[nbands];
    //          ores {18,19,20,21,22,23};
    int frequency[] = {0,0,0,0,0,0};

    int i,pos;

    for (i=0;i<nbands;i++){
    addBand(i,frequency);
    }

    pos = maxFrequencyPos(frequency);
    printf("%d",pos+18);
    return 0;
}

void addBand(int index,int frequency[]){
    float arrival,departure;
    char name[30];

    printf("Dwse onoma sygkrotimatos: ");
    gets(name);
    printf("Dwse ora afixis: ");
    arrival = GetReal();
    printf("Dwse ora anaxorisis: ");
    departure = GetReal();

    addFrequency(index,frequency,arrival,departure);

}

void addFrequency(int index,int frequency[],float arrivals, float departures){


    int i;

    for (i = round(arrivals); i<round(departures); i++ ){


        frequency[i-18]++;

    }
}

int maxFrequencyPos(int frequency[]){

    int max,i;
    max = frequency[0];

    for (i=1;i<6;i++){
        if (frequency[i]>max){
            max = frequency[i];
        }
    }
    return max;
}
