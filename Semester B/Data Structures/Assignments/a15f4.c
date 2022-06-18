#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int number;
    float weight;
    char date[11];
} StackElementType;           

typedef struct StackNode *StackPointer;

typedef struct StackNode{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TraverseStack(StackPointer Stack);

int numberOfBoxes(StackPointer warehouse);
int minWarehouse(StackPointer warehouse1,StackPointer warehouse2,StackPointer warehouse3);




int main(){
    StackPointer Warehouse1,Warehouse2,Warehouse3;
    int i,n,min;
    StackElementType AnItem;


    CreateStack(&Warehouse1);
    CreateStack(&Warehouse2);
    CreateStack(&Warehouse3);


    printf("Plithos fortiwn: ");
    scanf(" %d",&n);

    for(i=0;i<n;i++){
       
        printf("Arithmos kivwtiwn gia to %do fortio: ",i+1);
        scanf(" %d",&AnItem.number);
        printf("Synoliko baros gia to %do fortio: ",i+1);
        scanf(" %f",&AnItem.weight);
        printf("Imeromhnia liksis gia to %do fortio: ",i+1);
        scanf(" %s",AnItem.date);
        min = minWarehouse(Warehouse1,Warehouse2,Warehouse3);

        switch (min)
        {
        case 1:
            Push(&Warehouse1,AnItem);
            break;
        case 2:
            Push(&Warehouse2,AnItem);
            break;

        case 3:
            Push(&Warehouse3,AnItem);
            break;
        
        }
    }


        printf("Warehouse 1 \n");
        TraverseStack(Warehouse1);
        printf("Warehouse 2 \n");
        TraverseStack(Warehouse2);
        printf("Warehouse 3 \n");
        TraverseStack(Warehouse3);


    return 0;
}




void CreateStack(StackPointer *Stack){
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack){
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item){
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item; 
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item){
    StackPointer TempPtr;
    
    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;     
        free(TempPtr);
    }
}

void TraverseStack(StackPointer Stack){
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d %.2f %s\n", CurrPtr->Data.number,CurrPtr->Data.weight,CurrPtr->Data.date);
             CurrPtr = CurrPtr->Next;
        }
   }
}


int numberOfBoxes(StackPointer warehouse){

    int count = 0 ;
    StackPointer CurrPtr;

    CurrPtr = warehouse;

    while(CurrPtr != NULL){
        count += CurrPtr->Data.number;
        CurrPtr= CurrPtr->Next;
    }
    return count;
}

int minWarehouse(StackPointer warehouse1,StackPointer warehouse2,StackPointer warehouse3){

    int nWarehouse1 = numberOfBoxes(warehouse1);
    int nWarehouse2 = numberOfBoxes(warehouse2);
    int nWarehouse3 = numberOfBoxes(warehouse3);

    if(nWarehouse3<=nWarehouse2 && nWarehouse3<=nWarehouse1){
        return 3;
    }else if(nWarehouse2<=nWarehouse1 && nWarehouse2<=nWarehouse3){
        return 2;
    }else{
        return 1;
    }
}
