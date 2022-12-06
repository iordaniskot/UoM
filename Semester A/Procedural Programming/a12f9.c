#include <stdio.h>
#include <string.h>
#include "genlib.h"
#include "simpio.h"
#define N 100


typedef struct{

    long AFM;
    char name[29];
    float income;


}accountT;



void writeToFile(FILE *outfile , accountT array[],int size);
int readDataFromFile(FILE *infile,accountT array[]);

int main(){

    FILE *infile, *outfile;

    infile = fopen("i12f9.dat","r");
    outfile = fopen("Foro12f9.dat","w");
    int accountsNumber,i;
    accountT data[N];

    accountsNumber = readDataFromFile(infile,data);

    for(i=0;i<accountsNumber;i++){

        if(data[i].income<=10000){
            data[i].income*=0.14;
        }else if(data[i].income<=23000){
            data[i].income *=0.19;
        }else if(data[i].income<=55000){
            data[i].income *=0.23;
        }else{
            data[i].income*=0.28;
        }


    }




    writeToFile(outfile,data,accountsNumber);


    return 0;

}

int readDataFromFile(FILE *infile,accountT array[]){
    int counter=0;
    int nscan;
    char termch;

    while(TRUE){

        nscan = fscanf(infile,"%ld,%28[^,],%f%c",&array[counter].AFM,array[counter].name,&array[counter].income,&termch);

        if(nscan==EOF)break;
        if(nscan!=4 || termch!='\n'){


            printf("Error in line %d",counter+1);
            exit(1);
        }
        counter++;


    }

    return counter;
}

void writeToFile(FILE *outfile , accountT array[],int size){

    int i;
    float sum=0;
    fprintf(outfile,"%-10s%-29s%-7s\n","AFM","ONOMATEPWNUMO"," FOROS");
    fprintf(outfile,"-----------------------------------------------\n");
    for(i=0;i<size;i++){

            fprintf(outfile,"%-10ld%-29s%8.2f\n",array[i].AFM,array[i].name,array[i].income);
            sum += array[i].income;
    }
    fprintf(outfile,"-----------------------------------------------\n");
    fprintf(outfile,"%-20s%27.2f","SYNOLO FOROY",sum);






}
