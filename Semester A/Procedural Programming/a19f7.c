#include <stdio.h>
#include <string.h>
#include "genlib.h"
#include "simpio.h"

void getNames(char names[][20]);
void findAndPrintNames(char names[][20],char key);

int main(){


    char names[5][20];
    char key;


    getNames(names);
    printf("\nGive initial char:");
    key = getchar();
    findAndPrintNames(names,key);





    return 0;
}

void getNames(char names[][20]){

    int i;

    for(i=0;i<5;i++){
        printf("Give name %d: ",i);
        gets(names[i]);
    }

}

void findAndPrintNames(char names[][20],char key){

    int i;
    int count = 0;


    for(i=0;i<5;i++){

        if(key==names[i][0]){
            count++;
        }
    }

    printf("Names starting with %c are: %d\n",key,count);

     for(i=0;i<5;i++){

        if(key==names[i][0]){
            printf("%s\n",names[i]);
        }
    }

}
