#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NumberOfNodes 10
#define NilValue -1
#define StackLimit 4

typedef int StackElementType;

typedef struct {
    int Top;
    StackElementType Element[StackLimit];
} StackType; 


// List/Node 
typedef int ListPointer;


typedef struct {
    char name[20];
    int gymn;

}ListElementType;



typedef struct {
    int Next;
    ListElementType Data;
}NodeType;






// Boolean
typedef enum{
    FALSE, TRUE
}boolean;



void TraverseLinked(ListPointer List, NodeType Node[]);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
boolean FullList(ListPointer FreePtr);
boolean EmptyList(ListPointer List);
void CreateList(ListPointer *List);
void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);
// Stack
void CreateStack(StackType *Stack);
void Push(StackType *Stack, StackElementType Item);
boolean FullStack(StackType Stack);
boolean searchStack(StackType stack,int size,int posit);
void Pop(StackType *Stack, StackElementType *Item);
boolean EmptyStack(StackType Stack);



int main(){
  int i;
  NodeType phaseA[NumberOfNodes],phaseB[NumberOfNodes];
  ListPointer aStartPtr,aPrevPtr,aFreePtr,bStartPtr,bPrevPtr,bFreePtr;

  aPrevPtr = NilValue;
  bPrevPtr = NilValue;
  
  InitializeStoragePool(phaseA,&aFreePtr);
  InitializeStoragePool(phaseB,&bFreePtr);
  CreateList(&aStartPtr);
  CreateList(&bStartPtr);
  
  // A)
  FILE* infile;
  char name[20];
  int school,nscan;
  char linechange;
  ListElementType tmp;
  infile = fopen("students.dat","r");
  


  while(TRUE){

      nscan = fscanf(infile,"%s %d",name,&school);

      if(nscan == EOF){
          break;
      }

      if(nscan != 2){
          printf("Error!");
          exit(1);
      }
      strcpy(tmp.name,name);

      tmp.gymn = school;
      Insert(&aStartPtr,phaseA,&aFreePtr,aPrevPtr,tmp);
  }
  fclose(infile);

  printAll(aStartPtr,aFreePtr,phaseA);
  printf("Lista A\n");
  TraverseLinked(aStartPtr,phaseA);

  // B)
  ListPointer aCurrPtr;
  int posit;
  StackType posits;
  CreateStack(&posits);

  for(i=0;i<4;i++){
    
    while(TRUE){
      printf("Dwse thn thesh toy ma8hth poy klhrw8hke: ");
      scanf(" %d",&posit);
      if((posit>=0 && posit<10) && !searchStack(posits,i,posit)){
        Push(&posits,posit);
        break;
      }

    }
    aPrevPtr = NilValue;
    aCurrPtr = aStartPtr;
    while(aCurrPtr!=posit){
        aPrevPtr = aCurrPtr;
        aCurrPtr = phaseA[aCurrPtr].Next;
    }


    Insert(&bStartPtr,phaseB,&bFreePtr,bPrevPtr,phaseA[aCurrPtr].Data);

    Delete(&aStartPtr,phaseA,&aFreePtr,aPrevPtr);

    bPrevPtr = bStartPtr;
    while(phaseB[bPrevPtr].Next!=NilValue){
      bPrevPtr = phaseB[bPrevPtr].Next;
    }
  }
  printf("Question b:\n");
  printAll(aStartPtr,aFreePtr,phaseA);
  printf("Lista A\n");
  TraverseLinked(aStartPtr,phaseA);
  printAll(bStartPtr,bFreePtr,phaseB);
  printf("Lista B\n");
  TraverseLinked(bStartPtr,phaseB);

  // C

  bPrevPtr = NilValue;
  ListPointer bCurrPtr = bStartPtr;
  while(bCurrPtr!=1){
    bPrevPtr = bCurrPtr;
    bCurrPtr = phaseB[bCurrPtr].Next;
  }
  Insert(&aStartPtr,phaseA,&aFreePtr,aPrevPtr,phaseB[bCurrPtr].Data);
  Delete(&bStartPtr,phaseB,&bFreePtr,bPrevPtr);

    printf("Question c:\n");
  printAll(aStartPtr,aFreePtr,phaseA);
  printf("Lista A\n");
  TraverseLinked(aStartPtr,phaseA);
  printAll(bStartPtr,bFreePtr,phaseB);
  printf("Lista B\n");
  TraverseLinked(bStartPtr,phaseB);



  

  return 0;


}


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr){
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        strcpy(Node[i].Data.name,"");
        Node[i].Data.gymn=-1;
        Node[i].Next=i+1;

    }
    Node[NumberOfNodes-1].Next=NilValue;


    strcpy(Node[NumberOfNodes-1].Data.name,"");
    Node[NumberOfNodes-1].Data.gymn=-1;


    *FreePtr=0;
}



void CreateList(ListPointer *List){
  *List=NilValue;
}


boolean EmptyList(ListPointer List){
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr){
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]){
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}



void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr){
  Node[P].Next =*FreePtr;

  strcpy(Node[P].Data.name,"");
  Node[P].Data.gymn = -1; 



  *FreePtr =P;
}



void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item){
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {

        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    } 
    else
      {

        Node[TempPtr].Data =Item;

        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}


void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr){
  ListPointer TempPtr ;

  if (!EmptyList(*List)) {
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
      }
      ReleaseNode(Node,TempPtr,FreePtr);
  }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[]){
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d:<%s,%d> ->%d) ",CurrPtr,Node[CurrPtr].Data.name,Node[CurrPtr].Data.gymn,Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}


void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]){
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++){

        printf("(%d:<%s,%d> ->%d) ",i,Node[i].Data.name,Node[i].Data.gymn, Node[i].Next);
    }
    printf("\n");
}



void CreateStack(StackType *Stack){
    Stack -> Top = -1;

}


boolean FullStack(StackType Stack){
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item){
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}
void Pop(StackType *Stack, StackElementType *Item){
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}
boolean EmptyStack(StackType Stack){
    return (Stack.Top == -1);
}

boolean searchStack(StackType stack,int size,int posit){
  int i;
  int tmp;
  boolean found = FALSE;
  for(i=0;i<size;i++){
    Pop(&stack,&tmp);

    found = tmp==posit;
    Push(&stack,tmp);
    if(found){
      break;
    }
  }
  return found;
}