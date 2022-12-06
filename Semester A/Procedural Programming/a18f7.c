#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>



int integerConvertor(char string[],int index);
int main(){



    char name[10],input[20];
    int coef,mark,namelen,i;
    float final_mark;
    bool slashFound = FALSE;

    printf("Please insert course info (name/coef/mark): ");
    gets(input);

    for(i=0;i<10&&!slashFound;i++){
        if (input[i]=='/'){
            slashFound = TRUE;
        }
        else if(i!=10){
            name[i] = input[i];
        }
    }

    if(!slashFound){
        printf("Error! Name should not be more than 9 chars");
    }
    else{
        name[i+1] = '\0';

    coef = integerConvertor(input,i);
    mark = integerConvertor(input,i+3);
    final_mark = mark*coef/100.0;

    printf("lesson: %s\ncoef: %d\nmark: %d\nfinal mark: %.2f",name,coef,mark,final_mark);

    }



    return 0;
}


int integerConvertor(char string[],int index){

    char number[3];
    int i ;

    for(i=0;i<2;i++){
        number[i] = string[index+i];
    }
    number[i+1] = '\0';


    return atoi(number);
}
