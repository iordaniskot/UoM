#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>
#define N 50


typedef struct{

    char surname[20];
    char name[15];
    char address[30];
    int amount;

}patientT;

void getData(int size,patientT array[]);
void printData(char clinic[20], int size, patientT array[]);
int biggestAmountPatient(int size , patientT array[]);
int totalIncome(int size,patientT array[]);
void printPatient(patientT patient);
bool searchPatient(int size, patientT array[],patientT key,int *pos);

int main(){

    patientT patientsGalinos[N];
    patientT patientsElpis[N];
    patientT key;

    int galinosSize = 3;
    int elpisSize = 2;
    int keypos;

    int maxposGalinos,maxposElpis,incomeGalinos,incomeElpis;
    getData(galinosSize,patientsGalinos);
    getData(elpisSize,patientsElpis);

    printData("GALINOS",galinosSize,patientsGalinos);
    printData("ELPIS",elpisSize,patientsElpis);


    maxposGalinos = biggestAmountPatient(galinosSize,patientsGalinos);
    maxposElpis = biggestAmountPatient(elpisSize,patientsElpis);
    printPatient(patientsGalinos[maxposGalinos]);
    printPatient(patientsElpis[maxposElpis]);

    incomeGalinos = totalIncome(galinosSize,patientsGalinos);
    incomeElpis = totalIncome(elpisSize,patientsElpis);

    if(incomeElpis>incomeGalinos){
        printf("Max income ELPIS %d\n",incomeElpis);
    }else{
        printf("Max income GALINOS %d\n",incomeGalinos);
    }


    printf("Search a patient for GALINOS\n");
    printf("Give last name ");
    gets(key.surname);
    printf("Give first name ");
    gets(key.name);
    if(searchPatient(galinosSize,patientsGalinos,key,&keypos)== TRUE){
            printPatient(patientsGalinos[keypos]);

    }



    printf("Search a patient for ELPIS\n");
    printf("Give last name ");
    gets(key.surname);
    printf("Give first name ");
    gets(key.name);
    if(searchPatient(elpisSize,patientsElpis,key,&keypos)== TRUE){
            printPatient(patientsElpis[keypos]);

    }

    return 0;
}

void getData(int size,patientT array[]){

    int i;

    for(i=0;i<size;i++){

        printf("\nGive data patient %d\n",i);
        printf("Last name: ");
        gets(array[i].surname);
        printf("First name: ");
        gets(array[i].name);
        printf("Address: ");
        gets(array[i].address);
        printf("Amount: ");
        array[i].amount = GetInteger();


    }
}

void printData(char clinic[20], int size, patientT array[]){

    int i;

    printf("---------%s---------\n",clinic);
    printf("%-21s%-16s%-35s%s\n","Last name","First Name","Address","Amount");
    printf("------------------------------------------------------------------------------\n");
    for(i=0;i<size;i++){
        printf("%-21s%-16s%-35s%6d\n",array[i].surname,array[i].name,array[i].address,array[i].amount);
    }
}


int biggestAmountPatient(int size , patientT array[]){

    int i,maxpos;
    int maxAmount = -10;

    for(i=0;i<size;i++){
        if(maxAmount<array[i].amount){

                maxAmount = array[i].amount;
                maxpos = i;
        }
    }
    return maxpos;
}

int totalIncome(int size,patientT array[]){

    int sum = 0;
    int i;

    for(i=0;i<size;i++){

        sum += array[i].amount;
    }



    return sum;
}

void printPatient(patientT patient){


    printf("%-21s%-16s%-35s%s\n","Last name","First Name","Address","Amount");
    printf("------------------------------------------------------------------------------\n");
    printf("%-21s%-16s%-35s%6d\n",patient.surname,patient.name,patient.address,patient.amount);

}

bool searchPatient(int size, patientT array[],patientT key,int *pos){

    int i;

    for(i=0;i<size;i++){

        if(key.surname== array[i].surname && key.name == array[i].name){
                *pos = i;

                return TRUE;}

    }
        return FALSE;

}
