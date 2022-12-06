#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

void readGrade(int size, int grade[size]);
void calculateFrequency(int size,int grades[size],int freq[]);
int biggestFrequency(int frequencies[],int*frequency);
int smallestFrequency(int frequencies[],int*frequency);
void printResults(int frequencies[], int mostfreq,int bfreq,int leastfreq,int sfreq);



int main(){

    int grades[30];
    int frequencies[20] = {0};
    int bfrequency,mostfrequentgrade;
    int sfrequency,leastfrequentgrade;



    readGrade(30,grades);
    calculateFrequency(30,grades,frequencies);
    mostfrequentgrade = biggestFrequency(frequencies,&bfrequency);
    leastfrequentgrade = smallestFrequency(frequencies,&sfrequency);
    printResults(frequencies,mostfrequentgrade,bfrequency,leastfrequentgrade,sfrequency);
    return 0;
}


void readGrade(int size, int grade[size]){

    int i;

    for(i=0; i<size; i++){

        printf("Dwse bathmo %d: ",i+1);
        grade[i] = GetInteger();

    }


}

void calculateFrequency(int size,int grades[size],int freq[]){

    int i;

    for(i=0;i<size;i++){

        freq[grades[i]-1]++;
    }

}

int biggestFrequency(int frequencies[],int *frequency){

    int i;

    int max= frequencies[0];
    int maxpos = 0;

    for(i=1;i<20;i++){

        if(frequencies[i]>max){
            max = frequencies[i];
            maxpos = i;
        }

    }
    *frequency = max;
    return maxpos+1;

}


int smallestFrequency(int frequencies[],int *frequency){

    int i;

    int min= frequencies[0];
    int minpos = 0;

    for(i=1;i<20;i++){

        if(frequencies[i]<min){
            min = frequencies[i];
            minpos = i;
        }

    }
    *frequency = min;
    return minpos+1;

}


void printResults(int frequencies[], int mostfreq,int bfreq,int leastfreq,int sfreq){

    int i;

    printf("Syxnotites bathmwn\n");


    for(i=0;i<20;i++){

        printf("%d: %d\n",i+1,frequencies[i]);
    }

    printf("Bathmos me th megalyteri syxnotita: %d\n",mostfreq);
    printf("Syxnotita: %d\n",bfreq);
    printf("Bathmos me th mikroteri syxnotita: %d\n",leastfreq);
    printf("Syxnotita: %d",sfreq);

}
