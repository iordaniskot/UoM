#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct{
    char am[9];
    char first[11];
    char last[11];
} BinTreeElementType;       

typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr, int *nodes);

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);

void BuildBST(BinTreePointer *Root);



int main(){

    BinTreePointer ARoot,LocPtr;
    int num,i;
    BinTreeElementType student;
    boolean found;

    BuildBST(&ARoot);

    for(i=0;i<3;i++){

        printf("Give am:");
        scanf(" %s",student.am);
        BSTSearch(ARoot,student,&found,&LocPtr,&num);
        if(found){
            printf("komboi=%d AM=%s Onoma=%s Epwnymo=%s\n",num,LocPtr->Data.am,LocPtr->Data.first,LocPtr->Data.last);
        }else{
            printf("komboi=%d o foithths den brethike sto DDA\n",num);
        }

    }





   
    



    return 0;
}




void CreateBST(BinTreePointer *Root){
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root){
    return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item){
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if ((strcmp(Item.am,LocPtr->Data.am)<0))
            LocPtr = LocPtr ->LChild;
        else if (strcmp(Item.am,LocPtr->Data.am)>0)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("TO STOIXEIO EINAI HDH STO DDA\n");
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item.am,Parent->Data.am)<0)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,BinTreePointer *LocPtr,int *nodes){
    
    
    *nodes =0;
    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (strcmp(KeyValue.am,(*LocPtr)->Data.am)<0){

            (*LocPtr) = (*LocPtr)->LChild;
            (*nodes) ++;
        }
        else
            if (strcmp(KeyValue.am,(*LocPtr)->Data.am)>0){

                (*LocPtr) = (*LocPtr)->RChild;
                (*nodes) ++;
            }
            else {
              
                (*nodes) ++;
                (*Found) = TRUE;
            }
    }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent){
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (strcmp(KeyValue.am,(*LocPtr)->Data.am)<0) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (strcmp(KeyValue.am,(*LocPtr)->Data.am)>0) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue){

   BinTreePointer
   n,
   Parent,
   nNext,
   SubTree;
   boolean Found;

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO DEN EINAI STO DDA\n");
     else {
          if (n->LChild != NULL && n->RChild != NULL){
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
               
                n->Data = nNext->Data;
                n = nNext;
          }
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* 8A DIAGRAFEI H RIZA *)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s ",Root->Data.am);
        InorderTraversal(Root->RChild);
    }
}

void BuildBST(BinTreePointer *Root){

    FILE *fp;
    BinTreeElementType student;
    int nscan;

    CreateBST(Root);
    fp = fopen("i31f5.txt","r");

    if(fp==NULL){
        printf("Problem opening file");
    }else{
        while (!feof(fp)){
            fscanf(fp,"%s%s%s\n",student.am,student.first,student.last);
            BSTInsert(Root,student);
        }
        

    }
    fclose(fp);
}