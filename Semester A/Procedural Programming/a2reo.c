#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <string.h>
#define N 100

typedef struct{
    char name[30];
    int apousies;
}studentT;


void readInput(FILE *infile,studentT array[],int *plithosMathitwn,int *plithos100);
void writeOutput(FILE *outfile,int plithos100,studentT array[],int plithos);
int main(){

    FILE *infile;//A
    FILE *outfile;//C
    infile = fopen("i2f9.dat","r"); //A
    outfile = fopen("o2f9.dat","w");//C

    //B
    studentT students100[N];
    int studentsN = 0;
    int students100N = 0;

    readInput(infile,students100,&studentsN,&students100N);

    //D
    writeOutput(outfile,students100N,students100,studentsN);


    fclose(infile);//E
    fclose(outfile);//E
    return 0;
}

void readInput(FILE *infile,studentT array[],int *plithosMathitwn,int *plithos100){

    char name[30],info[68],termch;
    int apousies,nscan;

    while(TRUE){

        nscan = fscanf(infile,"%30[^,], %d, %68[^\n]%c",name,&apousies,info,&termch);

        if(nscan == EOF){
            break;
        }
        if(nscan != 4 || termch != '\n'){
            printf("Error!");
            exit(1);
        }

        if(apousies>100){

            strcpy(array[*plithos100].name,name);
            array[*plithos100].apousies = apousies;
            (*plithos100)++;
        }

        (*plithosMathitwn)++;

    }
}

void writeOutput(FILE *outfile,int plithos100,studentT array[],int plithos){

    int i;

    fprintf(outfile,"%-30s%-9s\n","ONOMATEPWNYMO","APOYSIES");
    for(i=0;i<39;i++){
        fputc('-',outfile);// idio me fprintf(outfile,"-");
    }
    fputc('\n',outfile);// idio me fputc('\n',outfile);

    for(i=0;i<plithos100;i++){
        fprintf(outfile,"%-30s%9d\n",array[i].name,array[i].apousies);
    }
    for(i=0;i<39;i++){
        fputc('-',outfile);// idio me fprintf(outfile,"-");
    }
    fputc('\n',outfile);// idio me fputc('\n',outfile);
    fprintf(outfile,"%-30s%9d\n","SYNOLO MATHITWN:",plithos);
    fprintf(outfile,"%-30s%9d\n","SYNOLO APONTWN:",plithos100);

}
