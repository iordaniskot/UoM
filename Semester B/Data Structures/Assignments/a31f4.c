#include <stdio.h>
#include <string.h>



#define NumberOfNodes 25
#define NumberOfNodes2 10

#define NilValue -1


// List/Node 
typedef int ListPointer;
typedef int ListElementType;

typedef struct {
    int class;
    int freq;

}ListElementType2;



typedef struct {
    int Next;
    ListElementType Data;
}NodeType;

typedef struct {
    int Next;
    ListElementType2 Data;
}NodeType2;




// Boolean
typedef enum{
    FALSE, TRUE
}boolean;



void TraverseLinked(ListPointer List, NodeType Node[]);
void TraverseLinked2(ListPointer List, NodeType2 Node[]);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Insert2(ListPointer *List, NodeType2 Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void GetNode2(ListPointer *P, ListPointer *FreePtr, NodeType2 Node[]);
boolean FullList(ListPointer FreePtr);
boolean EmptyList(ListPointer List);
void CreateList(ListPointer *List);
void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void InitializeStoragePool2(NodeType2 Node[], ListPointer *FreePtr);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);


void GetFrequences(NodeType ObsNode[],NodeType2 FreqNodep[],ListPointer ObsList,ListPointer FreqList);



int main(){
    int i,observationNumber,observation;
    NodeType observations[NumberOfNodes];
    NodeType2 frequences[NumberOfNodes2];
    NodeType2 temp;
    ListPointer freqStartPtr,freqFreePtr,freqPredPtr,obsStartPtr,obsFreePtr,obsPredptr;
    InitializeStoragePool(observations,&obsFreePtr);
    InitializeStoragePool2(frequences,&freqFreePtr);

    CreateList(&freqStartPtr);
    CreateList(&obsStartPtr);

    freqPredPtr = NilValue;
    obsPredptr = NilValue;

    for(i=0;i<10;i++){
      
      
      Insert2(&freqStartPtr,frequences,&freqFreePtr,freqPredPtr,i);
    }
    

    while(TRUE){
    // ΑΡΙΘΜΟΣ ΕΠΑΝΑΛΗΨΕΩΝ 
      printf("Enter an observation number: ");
      scanf("%d",&observationNumber);
    // ΕΛΕΓΧΟΣ ΕΚΓΥΡΟΤΗΤΑΣ
      if(observationNumber<=25&&observationNumber>0){
        break;
      }

    }

    for(i=0;i<observationNumber;i++){
      while(TRUE){
        // ΕΙΣΑΓΩΓΗ ΑΡΙΘΜΟΥ
        printf("Enter an observation in [0,9]: ");
        scanf(" %d",&observation);
        // ΕΛΕΓΧΟΣ ΕΓΚΥΡΟΤΗΤΑΣ
        if(observation >= 0 && observation <=9){
          break;
        }
      }
      // ΕΙΣΑΓΩΓΗ ΣΕ ΛΙΣΤΑ OBSERVATION
      Insert(&obsStartPtr,observations,&obsFreePtr,obsPredptr,observation);
    }
    printf("1h Lista Parathrhsewn\n");
    TraverseLinked(obsStartPtr,observations);

    GetFrequences(observations,frequences,obsStartPtr,freqStartPtr);

    printf("2h Lista Syxnothtwn\n");
    TraverseLinked2(freqStartPtr,frequences);



    return 0;


}


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr){
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;

        Node[i].Data=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;


    Node[NumberOfNodes-1].Data=-1;

    *FreePtr=0;
}

void InitializeStoragePool2(NodeType2 Node[], ListPointer *FreePtr){
   int i;

    for (i=0; i<NumberOfNodes2-1;i++)
    {
        Node[i].Next=i+1;

        Node[i].Data.class=-1;
        Node[i].Data.freq=0;
    }
    Node[NumberOfNodes2-1].Next=NilValue;

    Node[NumberOfNodes2-1].Data.class=-1;
    Node[NumberOfNodes2-1].Data.freq=0;

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

void GetNode2(ListPointer *P, ListPointer *FreePtr, NodeType2 Node[]){
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr){
  Node[P].Next =*FreePtr;

  Node[P].Data = -1; 



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
void Insert2(ListPointer *List, NodeType2 Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item){
  ListPointer TempPtr;
  GetNode2(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {

        Node[TempPtr].Data.class =Item;
        Node[TempPtr].Data.freq =0;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    } 
    else
      {

        Node[TempPtr].Data.class =Item;
        Node[TempPtr].Data.freq =0;
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
          printf("(%d) ",Node[CurrPtr].Data);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}


void TraverseLinked2(ListPointer List, NodeType2 Node[]){
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d:%d) ",Node[CurrPtr].Data.class,Node[CurrPtr].Data.freq);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]){
    int i;
    // printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++){

        printf("(%d:<%d,%d,%d> ->%d) ",i,Node[i].Data,Node[i].Data,Node[i].Data, Node[i].Next);
    }
    printf("\n");
}


void GetFrequences(NodeType ObsNode[],NodeType2 FreqNode[],ListPointer ObsList,ListPointer FreqList){



    ListPointer CurrObsPtr,CurrFreqPtr;
    ListElementType thisValue;
    
    
    if(!EmptyList(ObsList)){
        CurrObsPtr=ObsList;
        
        while(CurrObsPtr!=NilValue){
            thisValue = ObsNode[CurrObsPtr].Data;
            CurrFreqPtr = FreqList;

            while (CurrFreqPtr!=NilValue){
              if(FreqNode[CurrFreqPtr].Data.class==thisValue){
                FreqNode[CurrFreqPtr].Data.freq++;
                break;
              }else{
                CurrFreqPtr = FreqNode[CurrFreqPtr].Next;
              }
            }
            
        CurrObsPtr = ObsNode[CurrObsPtr].Next;
        }

        

    }else{
        printf("Empty List...\n");
    }

}