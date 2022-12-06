#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <string.h>
#define M 100

typedef struct{
    char epon[40];
    long upol;
    double epitok;
    int date;
}bankT;
int readFileData(bankT array[],char filename[30]);


int main()
{

    bankT newB[M];
    bankT oldB[M];
    bankT diffB[M];
    int oldN;
    int newN;
    int i,j;

    oldN = readFileData(oldB,"bank_old.dat");
    newN = readFileData(newB,"bank_new.dat");



    return 0;

}

int readFileData(bankT array[],char filename[30]) {

    int nscan;
    long upoloipo,hmerom;
    char epitheto,termch;
    double epitokio;
    FILE *infile;
    infile=fopen(filename,"r");
    int count = 0;

    while(TRUE){

        nscan = fscanf(infile,"%40[^,],%ld,%g,%d%c",epitheto,&upoloipo,&epitokio,&hmerom,&termch);

        if(nscan == EOF){
            break;
        }
        if(nscan != 5 || termch != '\n'){
            printf("Error!!");
            exit(1);
        }


        strcpy(array[count].epon,epitheto);
        array[count].upol = upoloipo;
        array[count].epitok = epitokio;
        array[count].date =  hmerom;
        count ++;
    }
    fclose(infile);
    return count;
}

int findDiff(int oldN,int newN,bankT oldB[],bankT newB[],bankT diffB[]){

    int i,j;
    int count = 0;

     for(i=0;i<newN;i++){
        for(j=0;j<oldN;j++){
            if(!strcmp(oldB[j].epon,newB[i].epon)){
                strcp(diffB[count].epon);
                break;
            }

        }
    }
}
