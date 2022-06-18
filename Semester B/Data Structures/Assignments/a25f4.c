#include <stdio.h>
#include <string.h>

#define NumberOfNodes 10
#define NilValue -1

// List/Node
typedef struct
{
  char name[20];
  int weight;
  int cost;
} ListElementType;

typedef int ListPointer;

typedef struct
{
  int Next;
  ListElementType Data;
} NodeType;

// Boolean
typedef enum
{
  FALSE,
  TRUE
} boolean;

void TraverseLinked(ListPointer List, NodeType Node[]);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void Insert(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
boolean FullList(ListPointer FreePtr);
boolean EmptyList(ListPointer List);
void CreateList(ListPointer *List);
void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

int main()
{
  boolean ascending;
  ListElementType tmp;
  int objects;

  int i;

  ListPointer FreePtr, StartPtr, PredPtr;
  NodeType Node[NumberOfNodes];
  // 1
  InitializeStoragePool(Node, &FreePtr);
  // 2
  CreateList(&StartPtr);
  // 3
  printAll(StartPtr, FreePtr, Node);
  // 4
  TraverseLinked(StartPtr, Node);
  // 5
  do
  {
    printf("Give objects number: ");
    scanf(" %d", &objects);

  } while (objects < 0 || objects > NumberOfNodes);
  // 6
  PredPtr = NilValue;
  for (i = 0; i < objects; i++)
  {
    printf("Give name: ");
    scanf(" %20s", tmp.name);
    printf("Give weight: ");
    scanf(" %d", &tmp.weight);
    printf("Give cost: ");
    scanf(" %d", &tmp.cost);
    Insert(&StartPtr, Node, &FreePtr, PredPtr, tmp);
  }
  // 7
  printAll(StartPtr, FreePtr, Node);
  // 8
  TraverseLinked(StartPtr, Node);

  return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
{
  int i;

  for (i = 0; i < NumberOfNodes - 1; i++)
  {
    Node[i].Next = i + 1;
    strcpy(Node[i].Data.name, "");

    Node[i].Data.weight = -1;
    Node[i].Data.cost = -1;
  }
  Node[NumberOfNodes - 1].Next = NilValue;
  strcpy(Node[NumberOfNodes - 1].Data.name, "");
  Node[NumberOfNodes - 1].Data.weight = -1;
  Node[NumberOfNodes - 1].Data.cost = -1;

  *FreePtr = 0;
}

void CreateList(ListPointer *List)
{
  *List = NilValue;
}

boolean EmptyList(ListPointer List)
{
  return (List == NilValue);
}

boolean FullList(ListPointer FreePtr)
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr = Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
{
  Node[P].Next = *FreePtr;
  strcpy(Node[P].Data.name, "");
  Node[P].Data.weight = -1;
  Node[P].Data.cost = -1;

  *FreePtr = P;
}

void Insert(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
{
  ListPointer TempPtr;
  GetNode(&TempPtr, FreePtr, Node);
  if (!FullList(TempPtr))
  {
    if (PredPtr == NilValue)
    {
      strcpy(Node[TempPtr].Data.name, Item.name);
      Node[TempPtr].Data.weight = Item.weight;
      Node[TempPtr].Data.cost = Item.cost;
      Node[TempPtr].Next = *List;
      *List = TempPtr;
    }
    else
    {
      strcpy(Node[TempPtr].Data.name, Item.name);
      Node[TempPtr].Data.weight = Item.weight;
      Node[TempPtr].Data.cost = Item.cost;
      Node[TempPtr].Next = Node[PredPtr].Next;
      Node[PredPtr].Next = TempPtr;
    }
  }
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
{
  ListPointer TempPtr;

  if (!EmptyList(*List))
  {
    if (PredPtr == NilValue)
    {
      TempPtr = *List;
      *List = Node[TempPtr].Next;
    }
    else
    {
      TempPtr = Node[PredPtr].Next;
      Node[PredPtr].Next = Node[TempPtr].Next;
    }
    ReleaseNode(Node, TempPtr, FreePtr);
  }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
    CurrPtr = List;
    while (CurrPtr != NilValue)
    {
      printf("(%s,%d,%d) \n", Node[CurrPtr].Data.name, Node[CurrPtr].Data.weight, Node[CurrPtr].Data.cost);
      CurrPtr = Node[CurrPtr].Next;
    }
    printf("\n");
  }
  else
    printf("Empty List ...\n");
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
  int i;
  // printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
  printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
  for (i = 0; i < NumberOfNodes; i++)
    printf("(%d:<%s,%d,%d> ->%d) ", i, Node[i].Data.name, Node[i].Data.weight, Node[i].Data.cost, Node[i].Next);
  printf("\n");
}

void sort_list(ListPointer *List, NodeType Node[], boolean Ascending, int choice)
{

  ListPointer OutPtr = *List;
  ListPointer tmpPtr;
  ListPointer PrevPtr, CurrPtr, NextPtr;
  boolean switched;
  while (OutPtr != NilValue)
  {
    ListPointer CurrPtr = *List;
    PrevPtr = CurrPtr - 1;
    NextPtr = CurrPtr + 1;
    switched = FALSE;
    while (NextPtr <= NumberOfNodes)
    {

      if (Ascending)
      {
        switch (choice)
        {

        case 1: // Name
          if (strcmp(Node[CurrPtr].Data.name, Node[NextPtr].Data.name))
          {
            tmpPtr = CurrPtr;
          }

          break;

        default:
          break;
        }
      }
    }
  }
}