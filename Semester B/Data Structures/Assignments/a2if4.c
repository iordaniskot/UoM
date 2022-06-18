#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ListElementType;           
typedef struct ListNode *ListPointer;   
typedef struct ListNode{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum{
    FALSE,TRUE
}boolean;

void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);

void intersection_list(ListPointer AList, ListPointer BList, ListPointer *FinalList);


int main(){

    int nList,i,ndelete;

    ListPointer  AList,BList,FinalList,PredPtr;
    ListElementType item;

    CreateList(&AList);
    CreateList(&BList);
    printf("DWSE TON PLI8OS TWN STOIXEIWN THS LISTAS 1: ");
    scanf(" %d",&nList);
    PredPtr = NULL;
    for(i=0;i<nList;i++){

        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXHTHS LISTAS: ");
        
        while(TRUE){
            
            scanf(" %d",&item);
            if(item>0)break; // Έλεγχος εγκυρότητας
            
        }
        LinkedInsert(&AList,item,PredPtr);
    }
    printf("DWSE TON PLI8OS TWN STOIXEIWN THS LISTAS 2: ");
    scanf(" %d",&nList);
    PredPtr = NULL;
    for(i=0;i<nList;i++){

        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXHTHS LISTAS: ");
        
        while(TRUE){
            
            scanf(" %d",&item);
            if(item>0)break; // Έλεγχος εγκυρότητας
            
        }
        LinkedInsert(&BList,item,PredPtr);
    }
    printf("1h lista\n");
    LinkedTraverse(AList);
    printf("2h lista\n");
    LinkedTraverse(BList);
    intersection_list(AList,BList,&FinalList);
    printf("Teliki lista\n");
    LinkedTraverse(FinalList);

  




    return 0; 
}



void CreateList(ListPointer *List){
	*List = NULL;
}
boolean EmptyList(ListPointer List){
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr){
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr){
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List){
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;
   	    // printf("%-16s\t%-4s\t%-16s\n", "CurrPtr","Data","Next");
         while ( CurrPtr!=NULL )
        {
             printf("%d ",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   printf("\n");
   }
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found){
   ListPointer CurrPtr;
   boolean stop;

   CurrPtr = List;
    *PredPtr=NULL;
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (CurrPtr->Data==Item )
         	stop = TRUE;
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
	*Found=stop;
}

void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found){
   ListPointer CurrPtr;
   boolean DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = FALSE;
   *Found = FALSE;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = TRUE;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}

void intersection_list(ListPointer AList, ListPointer BList, ListPointer *FinalList){

    ListPointer CurrPtr,CurrPtr2,PredPtr,Temp;
    CreateList(FinalList);
    boolean found;

    CurrPtr = AList;
    while(CurrPtr!=NULL){
        CurrPtr2 = BList;
        while (CurrPtr2!=NULL){
            if(CurrPtr->Data==CurrPtr2->Data){
                LinearSearch(*FinalList,CurrPtr->Data,&PredPtr,&found);
                if(!found){
                    LinkedInsert(FinalList,CurrPtr->Data,NULL);
                    break;
                }
            }
            CurrPtr2 = CurrPtr2->Next;
        }
        CurrPtr = CurrPtr->Next;
        
    }

}


