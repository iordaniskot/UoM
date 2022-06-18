#include <stdio.h>
#include <string.h>

#define NumberOfNodes 10
#define NilValue -1

#define StackLimit 11

typedef int StackElementType;

typedef struct {
    int Top;
    StackElementType Element[StackLimit];
} StackType; 


// List/Node 
typedef struct{
    int AM;
    float grade;
} ListElementType;

typedef int ListPointer;

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
boolean EmptyStack(StackType Stack);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);
float FindMaxs(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);



int main(){

    StackType AMs;
    int i,tmpAM;
    float maxGrade;
    ListPointer FreePtr,StartPtr,PredPtr;
    ListElementType tmp;
    NodeType Node[NumberOfNodes];
    // 1
    InitializeStoragePool(Node,&FreePtr);
    // 2
    CreateList(&StartPtr);
    // 3
    printAll(StartPtr,FreePtr,Node);
    // 4
    printf("Question 4\nLinked List\n");
    TraverseLinked(StartPtr,Node);
    // 5
    printf("Question 5\n");
    PredPtr = NilValue;
    for(i=0;i<5;i++){
        printf("DWSE AM GIA EISAGWGH STH LISTA: ");
        scanf(" %d",&tmp.AM);
        printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
        scanf(" %f",&tmp.grade);
        Insert(&StartPtr,Node,&FreePtr,PredPtr,tmp);

    }
    // 6
    printf("Question 6\nStorage pool\n");
    printAll(StartPtr,FreePtr,Node);
    // 7
    printf("Question 7\nLinked list\n");
    TraverseLinked(StartPtr,Node);
    // 8
    printf("Question 8\n");
    if(!EmptyList(StartPtr)){
        printf("Not an Empty List\n");
    }else{
        printf("Empty List\n");
    }
    // 9
    printf("Question 9\n");
    if(!FullList(FreePtr)){
        printf("Not a Full List\n");
    }else{
        printf("Full List\n");
    }
    // 10
    printf("Question 10\n");
    maxGrade = FindMaxs(StartPtr,Node,&AMs);
    printf("Max vathmos: %.1f\nAM me megisto vathmo: ",maxGrade);
    while(!EmptyStack(AMs)){
      Pop(&AMs,&tmpAM);
      printf("%d ",tmpAM);
    }
    printf("\nQuestion 11\n");
    TraverseStack(AMs);
    // 12
    printf("\nQuestion 12\n");
    printf("Storage pool\n");
    printAll(StartPtr,FreePtr,Node);
    // 13
    printf("Question 13\n");
    printf("Linked list\n");
    TraverseLinked(StartPtr,Node);




    return 0;
}


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr){
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.AM=-1;
        Node[i].Data.grade=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.AM=-1;
    Node[NumberOfNodes-1].Data.grade=-1;

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
  Node[P].Data.AM = -1; 
  Node[P].Data.grade = -1; 

  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item){
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data.AM =Item.AM;
        Node[TempPtr].Data.grade =Item.grade;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data.AM =Item.AM;
        Node[TempPtr].Data.grade =Item.grade;
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
          printf("(%d:<%d,%.1f> ->%d) ",CurrPtr,Node[CurrPtr].Data.AM,Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
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
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d:<%d,%.1f> ->%d) ",i,Node[i].Data.AM,Node[i].Data.grade, Node[i].Next);
    printf("\n");
}


void CreateStack(StackType *Stack){
    Stack -> Top = -1;
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

boolean FullStack(StackType Stack){
    return (Stack.Top == (StackLimit - 1));
}

boolean EmptyStack(StackType Stack){
    return (Stack.Top == -1);
}

void TraverseStack(StackType Stack){
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

float FindMaxs(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack){

    ListPointer CurrPtr;
    float max = 0;
    float grade;
    
    if(!EmptyList(List)){

      CreateStack(Stack);
      CurrPtr = List;
      while(CurrPtr!=NilValue){
        grade =Node[CurrPtr].Data.grade;
        if(grade>=max){
          if(grade>max){
            CreateStack(Stack);
            max = grade;
          }
          Push(Stack,Node[CurrPtr].Data.AM);
        }
        CurrPtr--;
      }
    }
    return max;
}