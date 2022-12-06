#include "genlib.h"
#include <stdio.h>
#include "simpio.h"
#include "string.h"
#define PERSONS 13

void swapNames(char *name1,char *name2);
int oneCount(int array[]);
int mostOnes(int size,int array[PERSONS][PERSONS]);
void swapPerson(int array1[], int array2[]);
void removePerson(int array[PERSONS][PERSONS], int pos);

int main(){
    int i,j,k;

    int deleted = 0;
    int accepted = 0;
    int size;
    int mostpos;
    int node [PERSONS][PERSONS]={

                          {0,1,0,0,0,0,1,0,0,0,0,0,0},
                          {1,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,1,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,1,0,0,0,0,0},
                          {0,0,0,0,0,0,1,0,0,0,0,0,0},
                          {0,0,1,0,0,0,1,1,0,0,0,0,0},
                          {1,0,0,0,1,1,0,0,0,0,0,0,0},
                          {0,0,0,1,0,1,0,0,0,1,1,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,1,0,0,1,1,0},
                          {0,0,0,0,0,0,0,1,0,1,0,0,0},
                          {0,0,0,0,0,0,0,0,0,1,0,0,1},
                          {0,0,0,0,0,0,0,0,0,0,0,1,0}

                        };
    char names[PERSONS][20]={"Nikos","Lydia","Eva","Petros","Giannis","Manos","Akis","Eleni","Zoi","Maria","Dimitris","Aleksandros","Anna"};
    int deletedIndexes[PERSONS];


    for(i=0;i<PERSONS;i++){

        printf("%d. %d || ",i,oneCount(node[i]));
    }


    for(k = 0;k<PERSONS;k++){
        printf("\n %3d.  ",k);
        for(j=0;j<PERSONS;j++){
            printf("%d ",node[k][j]);
        }
    }

    size = PERSONS - (accepted+deleted);



            mostpos = mostOnes(size,node);    while(size-accepted-deleted>0){
        for(i=0;i<size-accepted-deleted;i++){
            if(oneCount(node[i])==0){

            printf("\n||Dinw to%d||",i+1);

                accepted++;
                swapNames(names[i],names[size-accepted-deleted]);
                swapPerson(node[i],node[size-accepted-deleted]);
            }
            }

            printf("\n||Svinw to%d||",mostpos);

            deleted++;
            swapNames(names[mostpos],names[size-accepted-deleted]);
            removePerson(node,mostpos);
            swapPerson(node[mostpos],node[size-accepted-deleted]);

            mostpos = mostOnes(size,node);


        printf("\n\n");
        for(k = 0;k<PERSONS;k++){
        printf("\n %3d.  ",k+1);
        for(j=0;j<PERSONS;j++){
            printf("%d ",node[k][j]);
        }
    }


    }




    printf("\n\n %d",accepted);
    printf("\n\n %d",deleted);


    return 0;
}

void swapNames(char *name1,char *name2){
   char temp[20];
   strcpy(temp, name1);
   strcpy(name1, name2);
   strcpy(name2, temp);

}

int oneCount(int array[]){

    int i;
    int counter = 0;
    for(i=0;i<PERSONS;i++){

            if (array[i]==1){
                counter++;
            }
    }

    return counter;
}

int mostOnes(int size,int array[PERSONS][PERSONS]){


    int i,j,pos,max,ones;

    pos = 0;
    max =0;

    for(i=0;i<size;i++){

        ones=oneCount(array[i]);
        if(max<ones){
            max = ones;
            pos = i;
        }
    }

    return pos;
}


void swapPerson(int array1[], int array2[]){

    int i,j;

    for(i=0;i<PERSONS;i++){

        array1[i] = array2[i];
        array2[i] = 0;

        }
    }


void removePerson(int array[PERSONS][PERSONS], int pos){

    int i;

    for(i=0;i<PERSONS;i++){
        array[i][pos] = 0;
    }
}
