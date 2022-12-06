#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define TOWNSGR 5
#define TOWNSCY 2
#define PRICEGR 7.5
#define PRICECY 8.5
#define MONTHS 3


void monthlyIncome(int towns, int months,float array[towns][months],float price);
void averageTown(int towns, int months,float income[towns][months] ,float array[]);
void averageMonth(int towns, int months,float income[towns][months] ,float array[]);
void smallestIncome(int towns, int months, float income[towns][months],float *minIncome,int *minCity,int *minMonth);
void printResults(int towns,int months, float income[towns][months]);
void printStatistics(int towns,int months,float averageMonth[],float averageTown[],float minIncome,int minTown,int minMonth);

int main(){

    float incomeGR[TOWNSGR][MONTHS];
    float incomeCY[TOWNSCY][MONTHS];

    float townsAverageGR[TOWNSGR];
    float townsAverageCY[TOWNSCY];

    float monthsAverageGR[MONTHS];
    float monthsAverageCY[MONTHS];

    float minIncomeGR,minIncomeCY;
    int minMonthGR,minMonthCY,minTownGR,minTownCY;


    printf("Tickets in Greece\n");
    monthlyIncome(TOWNSGR,MONTHS,incomeGR,PRICEGR);
    printf("Tickets in Cyprus\n");
    monthlyIncome(TOWNSCY,MONTHS,incomeCY,PRICECY);

    averageTown(TOWNSGR,MONTHS,incomeGR,townsAverageGR);
    averageTown(TOWNSCY,MONTHS,incomeCY,townsAverageCY);

    averageMonth(TOWNSGR,MONTHS,incomeGR,monthsAverageGR);
    averageMonth(TOWNSCY,MONTHS,incomeCY,monthsAverageCY);

    smallestIncome(TOWNSGR,MONTHS,incomeGR,&minIncomeGR,&minTownGR,&minMonthGR);
    smallestIncome(TOWNSCY,MONTHS,incomeCY,&minIncomeCY,&minTownCY,&minMonthCY);

    printf("\nCinema revenues in Greece\n");
    printResults(TOWNSGR,MONTHS,incomeGR);
    printf("\nStatistics in Greece\n");
    printStatistics(TOWNSGR,MONTHS,monthsAverageGR,townsAverageGR,minIncomeGR,minTownGR,minMonthGR);



    printf("\nCinema revenues in Cyprus\n");
    printResults(TOWNSCY,MONTHS,incomeCY);
    printf("\nStatistics in Cyprus\n");
    printStatistics(TOWNSCY,MONTHS,monthsAverageCY,townsAverageCY,minIncomeCY,minTownCY,minMonthCY);

    return 0;

}



void monthlyIncome(int towns, int months,float array[towns][months],float price){


    int tickets,i,j;

    for (i=0;i<towns;i++){
        for (j=0;j<months;j++){
            printf("Give tickets: [%d][%d]: ",i,j);
            tickets = GetInteger();
            array[i][j] = tickets*price;

        }
    }

}


void averageTown(int towns, int months,float income[towns][months] ,float array[]){

    int i,j;
    float sum;

    for(i=0;i<towns;i++){
        sum = 0;
        for(j=0;j<months;j++){
            sum+=income[i][j];
        }
        array[i] = sum/months;
    }
}




void averageMonth(int towns, int months,float income[towns][months] ,float array[]){

    int i,j;
    float sum;

    for(i=0;i<months;i++){
        sum = 0;
        for(j=0;j<towns;j++){
            sum+=income[j][i];
        }
        array[i] = sum/towns;
    }
}

void smallestIncome(int towns, int months, float income[towns][months],float *minIncome,int *minCity,int *minMonth){

    int i,j;

    *minIncome=income[0][0];
    *minCity = 0;
    *minMonth = 0;

    for(i=0;i<towns;i++){
        for(j=0;j<months;j++){

            if(*minIncome>income[i][j]){
                *minIncome = income[i][j];
                *minCity = i;
                *minMonth= j;
            }
        }
    }
}


void printResults(int towns,int months, float income[towns][months]){


    int i,j;

    for(i=0;i<towns;i++){
        printf("City %d:   ",i);
        for(j=0;j<months;j++){
            printf("%6.2f ",income[i][j]);
        }
        printf("\n");

    }
}


void printStatistics(int towns,int months,float averageMonth[],float averageTown[],float minIncome,int minTown,int minMonth){

    int i;



    printf("Cities average revenues\n");
    for(i=0;i<towns;i++){
        printf("%d: %6.2f\n",i,averageTown[i]);
    }
    printf("Months average revenues\n");
    for(i=0;i<months;i++){
        printf("Month %d: %6.2f\n",i,averageMonth[i]);
    }
    printf("Min revenue:  %6.2f\n",minIncome);
    printf("City: %d\n",minTown);
    printf("Month: %d\n",minMonth);



}
