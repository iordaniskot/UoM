#include <stdio.h>
#include <string.h>
#define megisto_plithos 255


typedef enum{
    FALSE,TRUE
}boolean;
typedef boolean typos_synolou[megisto_plithos+1];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);

boolean isValidInteger(char s[],typos_synolou DigitSet,typos_synolou CharachterSet);
boolean isValidIdentifier(char s[],typos_synolou DigitSet,typos_synolou LetterSet);

int main(){

    typos_synolou CharachterSet,DigitSet,LetterSet;
    
    char s[30],choice;
    int i;

    Dimiourgia(CharachterSet);
    Dimiourgia(DigitSet);
    Dimiourgia(LetterSet);

// Εισαγωγή Χαρακτήρων +,-
    
    Eisagogi(43,CharachterSet);
    Eisagogi(45,CharachterSet);

//  Εισαγωγή πεζών
    
    for(i=65;i<91;i++){
        
        Eisagogi(i,LetterSet);

    }
    
    for(i=97;i<123;i++){
        
        Eisagogi(i,LetterSet);

    }
    
// Εισαγωγή Αριθμών

    for(i=48;i<58;i++){
        
        Eisagogi(i,DigitSet);

    }

// Έλεγχος ακεραίων
    while(TRUE){

        printf("Get an integer: ");
        scanf(" %s",s);

        if(isValidInteger(s,DigitSet,CharachterSet)){
            printf("Correct integer\n");
        }else{
            printf("Wrong integer\n");
        }

        printf("Continue with more integers (Y or N): ");
        scanf(" %c",&choice);
        while(choice != 'y' && choice != 'Y' && choice != 'N' && choice != 'n' ){
           printf("Continue with more integers (Y or N): ");
            scanf(" %c",&choice);
        }
        if (choice == 'n' || choice =='N'){
            break;
        }
    }
    
// Έλεγχος μεταβλητών
    while(TRUE){

        printf("Give an identifier: ");
        scanf(" %s",s);

        if(isValidIdentifier(s,DigitSet,LetterSet)){
            printf("Correct identifier\n");
        }else{
            printf("Wrong identifier\n");
        }

        printf("Continue with more identifiers (Y or N): ");
        scanf(" %c",&choice);

        while(choice != 'y' && choice != 'Y' && choice != 'N' && choice != 'n' ){
           printf("Continue with more identifiers (Y or N): ");
           scanf(" %c",&choice);
        }
        
        if (choice == 'n' || choice =='N'){
            break;
        }
    }

    return 0;
}


void Dimiourgia(typos_synolou synolo){
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}


void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo){
    synolo[stoixeio] = TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo){
    return synolo[stoixeio];
}


boolean isValidInteger(char s[],typos_synolou DigitSet,typos_synolou CharachterSet){

    int i;


    for(i=0;i<strlen(s);i++){
        if (!(Melos(s[i],DigitSet)|| Melos(s[i],CharachterSet))){
            return FALSE;
        }
    }

    return TRUE;
}

boolean isValidIdentifier(char s[],typos_synolou DigitSet,typos_synolou LetterSet){

    int i;

    if(!Melos(s[0],LetterSet)){
        return FALSE;
    }
    for(i=1;i<strlen(s);i++){
        if (!(Melos(s[i],DigitSet)|| Melos(s[i],LetterSet)||s[i]=='_')){
            return FALSE;
        }
    }

    return TRUE;
}