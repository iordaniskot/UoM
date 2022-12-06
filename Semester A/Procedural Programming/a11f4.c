#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

bool IsLeapYear(int year);
bool Valide_Date(int day, int month, int year);
long Read_and_Calculate(int current_year);
int main(){

    int current_year;
    long total_fpa;


    printf("Current year ? ");
    current_year = GetInteger();

    total_fpa = Read_and_Calculate(current_year);
    printf("SYNOLO FPA ---> %ld",total_fpa);

    return 0;
}



long Read_and_Calculate(int current_year){

    int day,month,year,fpa;
    long total_fpa;

    total_fpa = 0;
    printf("Day ? ");
    day = GetInteger();
    while (day != -1){


        printf("Month ? ");
        month = GetInteger();

        printf("Year ? ");
        year = GetInteger();


        printf("FPA ? ");
        fpa = GetInteger();

        if (Valide_Date(day,month,year) && current_year ==year){
            total_fpa += fpa;
        }


        printf("Day ? ");
        day = GetInteger();

    }




    return total_fpa;
}





bool Valide_Date(int day, int month, int year){
    int correct_date;

    switch (month){

    case 1: case 3: case 5:case 7: case 8: case 10: case 12:
        correct_date=31;
        break;
    case 2:
        correct_date = 28;
        break;
    case 4: case 6: case 9: case 11:
        correct_date = 30;
        break;
    default:

        return FALSE;
    }

    if (IsLeapYear(year) && month ==2){
        correct_date ++;

    }

    if (day<=correct_date){
        return TRUE;
    }
    return FALSE;

}

bool IsLeapYear(int year)
{
    return ( ((year % 4 == 0) && (year % 100 != 0))
             || (year % 400 == 0) );
}
