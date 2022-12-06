#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <stdlib.h>
#include <time.h>




void randomGrade(int students, int lessons,int grades[students][lessons]);
void calculateGPA(int students, int lessons, int grades[students][lessons],float gpa[students]);
void printResults(int students,int lessons,int grades[students][lessons],float gpa[students]);
void percentages(int students,float gpa[students],int*excellent,int*failed,float *pexcellent,float *pfailed);


int main(){

    int students=30;
    int lessons=3;
    int grades[students][lessons];
    float gpa[students];
    int excellent,failed;
    float pexcellent,pfailed;

    randomGrade(students,lessons,grades);
    calculateGPA(students,lessons,grades,gpa);
    printResults(students,lessons,grades,gpa);
    percentages(students,gpa,&excellent,&failed,&pexcellent,&pfailed);

    printf("Apotyxontes: %d\nPososto apotyxonton: %.2f%%\nAristouxoi: %d\nPososto Aristouxwn: %.2f%%",failed,pfailed,excellent,pexcellent);

    return 0;
}





void randomGrade(int students, int lessons,int grades[students][lessons]){

    int i,j;
    srand(time(NULL));

    for (i=0;i<students;i++){
        for(j=0;j<lessons;j++){

            grades[i][j]= rand()%21;
        }
    }
}

void calculateGPA(int students, int lessons, int grades[students][lessons],float gpa[students]){

    int i,j,sum;

    for(i=0;i<students;i++){
        sum =0;
        for(j=0;j<lessons;j++){
            sum += grades[i][j];
        }
        gpa[i] = sum/(float)lessons;
    }

}


void printResults(int students,int lessons,int grades[students][lessons],float gpa[students]){

    int i,j;


    for(i=0;i<students;i++){
            printf("%2d:",i+1);
        for(j=0;j<lessons;j++){

            printf("%3d",grades[i][j]);
        }
        printf(" : %5.2f\n",gpa[i]);

    }


}

void percentages(int students,float gpa[students],int*excellent,int*failed,float *pexcellent,float *pfailed){

    int i;
    *failed=0;
    *excellent=0;
    for(i=0;i<students;i++){

        if(gpa[i]<9.5){

            *failed +=1;
        }
        else if(gpa[i]>=18.5){

            *excellent +=1;
        }
    }

    *pexcellent = *excellent/(float)students*100;
    *pfailed = *failed/(float)students*100;





}
