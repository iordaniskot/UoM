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

void delete_n_element (ListPointer *List, int n);


int main(){

    int nList,i,ndelete;

    ListPointer  List,PredPtr;
    ListElementType item;

    CreateList(&List);
    printf("DWSE TON PLI8OS TWN STOIXEIWN THS LISTAS: ");
    scanf(" %d",&nList);
    PredPtr = NULL;
    for(i=0;i<nList;i++){

        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXHTHS LISTAS: ");
        
        while(TRUE){
            
            scanf(" %d",&item);
            if(item>0)break; // Έλεγχος εγκυρότητας
            
        }
        LinkedInsert(&List,item,PredPtr);
    }
    
     while(TRUE){
        printf("DWSE TI THSESI GIA DIAGRAFI TOY STOIXEIOY: ");
            
        scanf(" %d",&ndelete);
        if(ndelete>0 && ndelete<=nList)break; // Έλεγχος εγκυρότητας
        }
    printf("Arxikh Lista\n");
    LinkedTraverse(List);
    delete_n_element(&List,ndelete);
    printf("Teliki Lista\n");
    LinkedTraverse(List);




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


void delete_n_element (ListPointer *List, int n){
    
    ListPointer TempPtr,PrePtr;
    int i;

    if(!EmptyList(*List)){

        if(n==1){
            TempPtr = *List;
            *List = TempPtr->Next;
        }else{

            PrePtr = *List;
            TempPtr = PrePtr->Next;
            for(i=2;i<n;i++){
                PrePtr = PrePtr->Next;
                TempPtr = TempPtr->Next;
            }
            PrePtr->Next= TempPtr->Next;

        }
        free(TempPtr);
    }

}

