#include <stdio.h>
#include <string.h>
#define megisto_plithos 256

typedef enum{
    FALSE,TRUE
}boolean;

typedef boolean typos_synolou[megisto_plithos+1];
typedef int stoixeio_synolou;


void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void displayset(typos_synolou set);
int vowelCount(char s[],typos_synolou vowels,typos_synolou alphabet);
void createAlphabetSet(typos_synolou alphabet);
void createVowelSet(typos_synolou vowels);
boolean isVowel(char s,typos_synolou synolo);



int main(){
    typos_synolou vowels,alphabet;
    char key[80];
    int i,vowelNumber;


    createAlphabetSet(alphabet);
    createVowelSet(vowels);
    displayset(alphabet);
    displayset(vowels);

    for(i=0;i<3;i++){
        vowelNumber =0;
        printf("Give string with uppercase charachters: ");
        scanf(" %80[^\n]",key);
        vowelNumber = vowelCount(key,vowels,alphabet);
        printf("Number of vowels: %d\n",vowelNumber);
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

void displayset(typos_synolou set)
{
	stoixeio_synolou i;

	for (i=0;i < megisto_plithos;i++)
	{
		if(Melos(i,set))
			printf(" %c",i);
	}
	printf("\n");
}

int vowelCount(char s[],typos_synolou vowels,typos_synolou alphabet){

    int sum = 0;
    int i ;

    for(i=0;i<strlen(s);i++){
        if(Melos(s[i],vowels)){
            sum ++;
        }else if(!(Melos(s[i],alphabet))){
            printf("Invalid charachter decteted: %c-%d\n",s[i],s[i]);
        }
    }

    return sum;
}

void createAlphabetSet(typos_synolou alphabet){

    int i;

    Dimiourgia(alphabet);

    for(i=65;i<91;i++){
        Eisagogi(i,alphabet);
    }
}

void createVowelSet(typos_synolou vowels){


    Dimiourgia (vowels);

    Eisagogi(65,vowels);
    Eisagogi(69,vowels);
    Eisagogi(73,vowels);
    Eisagogi(79,vowels);
    Eisagogi(85,vowels);
    Eisagogi(89,vowels);


}

boolean isVowel(char s,typos_synolou synolo){
    return Melos(s,synolo);
}



