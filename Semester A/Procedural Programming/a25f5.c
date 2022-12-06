#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define ROWS 12
#define COLUMNS 4

void upDateSeats(int row, int col, int tab[row][col]);
void findEmptyRows(int rows, int columns, int tab[rows][columns]);
void findFirstAvailableWindow(int rows, int columns, int tab[rows][columns]);

int main() {

  int seats[ROWS][COLUMNS] = {{1,0,   0, 1},
                              {1,0,   0, 1},
                              {0,1,   0, 0},
                              {0,0,   1, 1},
                              {1,1,   0, 0},
                              {1,1,   0, 1},
                              {0,0,   1, 1},
                              {1,0,   0, 0},
                              {0,0,   1, 0},
                              {0,0,   0, 0},
                              {0,0,   0, 0},
                              {1,1,   0, 1}};




  upDateSeats(ROWS,COLUMNS,seats);
  findEmptyRows(ROWS,COLUMNS,seats);
  findFirstAvailableWindow(ROWS,COLUMNS,seats);

  return 0;
}

/* Function for Testing. */
void upDateSeats(int rows, int cols, int tab[rows][cols]){
   int i,j;
   printf("Update Seats? (0/no):");
   if(!GetInteger()) return;
   for(i=0;i<rows;i++)
      for(j=0;j<cols;j++)
         tab[i][j] = (printf("seat (%2d,%2d)",i,j),GetInteger());
    printf("\n");
}

void findEmptyRows(int rows, int columns, int tab[rows][columns]){

    int i,j,sum;

    for (i=0; i<rows; i++){
        sum = 0;
        j=0;
        while(sum == 0 && j<columns){
            sum += tab[i][j];
            j++;

        }
        if (sum==0){
        printf("Row: %d\n",i);
        }
    }
}


void findFirstAvailableWindow(int rows, int columns, int tab[rows][columns]){


    int i,j;


    for(i=0;i<rows;i++){
        for(j=0;j<columns;j+=3){
            if(tab[i][j]==0){
                printf("First available window seat: %d,%d",i,j);
                return;
            }
        }
    }




}



