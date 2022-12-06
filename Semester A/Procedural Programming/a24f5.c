#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>



void ReadPolynomial (int size, int cofficients[]);
void PrintPolynomial (int degree, int coefficients[]);
void AddPolynomial(int degree , int coefficentsA[], int coefficentsB[], int coefficentsSum[]);
int CalculateValue(int x, int degree, int coefficient[]);

int main() {

    int degree;
    int coefficientsA[10], coefficientsB[10], coefficientsSum[10];
    int i;
    double x, value1, value2, valueSum;

    //Ανάγνωση βαθμού πολυωνύμων
    printf("Ti vathmo exoyn ta polywnyma?\n");
    degree = GetInteger();

    //Ανάγνωση συντελεστών πρώτου πολυωνύμου
   //for(i=0; i<=degree; i++) {
   //     printf("Eisagete to syntelesti tou orou %d: ", i);
     //   coefficientsA[i] = GetInteger();
    //}
    ReadPolynomial(degree,coefficientsA);

    //Εκτύπωση πρώτου πολυωνύμου
    //i=degree;
    //while(i>=1) {
    //    printf("%dx^%d + ", coefficientsA[i], i);
    //    i--;
    //}
    //printf("%d\n", coefficientsA[0]);

    PrintPolynomial(degree,coefficientsA);

    //Ανάγνωση συντελεστών δεύτερου πολυωνύμου
    //for(i=0; i<=degree; i++) {
    //    printf("Eisagete to syntelesti tou orou %d: ", i);
    //    coefficientsB[i] = GetInteger();
    //}

    ReadPolynomial(degree,coefficientsB);
    //Εκτύπωση δεύτερου πολυωνύμου

    //i=degree;
    //while(i>=1) {
    //    printf("%dx^%d + ", coefficientsB[i], i);
    //    i--;
    //}
    //printf("%d\n", coefficientsB[0]);

    PrintPolynomial(degree,coefficientsB);

    //πρόσθεση πολυωνύμων
   // for(i=0; i<=degree; i++) {
   //     coefficientsSum[i] = coefficientsA[i] + coefficientsB[i];
   //}

    AddPolynomial(degree,coefficientsA,coefficientsB,coefficientsSum);

    //Εκτύπωση αθροίσματος
    //i=degree;
    //while(i>=1) {
    //    printf("%dx^%d + ", coefficientsSum[i], i);
    //    i--;
    //}
    //printf("%d\n", coefficientsSum[0]);
    PrintPolynomial(degree,coefficientsSum);

    printf("Dwse mia timi gia to x: ");
    x = GetReal();

    //Εκτύπωση τιμών πολυωνύμων
   // value1 = 0;
   // for(i=0; i<=degree; i++)
   //     value1 += coefficientsA[i]*pow(x, (double)i);
    value1 = CalculateValue(x, degree, coefficientsA);
    //value2 = 0;
   // for(i=0; i<=degree; i++)
    //    value2 += coefficientsB[i]*pow(x, (double)i);
    value2 = CalculateValue(x, degree, coefficientsB);
   // valueSum = 0;
   // for(i=0; i<=degree; i++)
   //     valueSum += coefficientsSum[i]*pow(x, (double)i);
    valueSum= CalculateValue(x, degree, coefficientsSum);
    printf("Value1: %g  Value2: %g  Value of Sum: %g", value1, value2, valueSum);

    return 0;
}

void ReadPolynomial (int size, int cofficients[]){
    int i;
    for (i = 0; i<=size; i++){
        printf("Eisagete to syntelesti tou orou %d: ",i);
        cofficients[i] = GetInteger();

    }
}

void PrintPolynomial (int degree, int coefficients[]){
    int i = degree;
    while (i>=1){

        printf("%dx^%d + ",coefficients[i],i);

        i--;
    }
    printf("%d\n",coefficients[0]);

}

void AddPolynomial(int degree , int coefficentsA[], int coefficentsB[], int coefficentsSum[]){
    int i;

    for (i = 0; i<=degree; i++){
        coefficentsSum[i] = coefficentsA[i] +coefficentsB[i];
    }
}

int CalculateValue(int x, int degree, int coefficient[]){

    int value = 0;
    int i;

    for (i = 0; i<=degree; i++){
        value += coefficient[i]*pow(x, (double)i);
    }

    return value;

}
