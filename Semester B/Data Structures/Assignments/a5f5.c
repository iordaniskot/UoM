#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef char BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode
{
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum
{
    FALSE,
    TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);

int BSTLevel(BinTreePointer Root, BinTreeElementType Item);

int main()
{

    BinTreePointer ARoot, BRoot;
    BinTreePointer TempPtr;
    int level, i;
    char word[] = "PROGRAMS";
    int wordlen = strlen(word);
    boolean found;

    CreateBST(&ARoot);
    CreateBST(&BRoot);

    // Add BST
    for (i = 0; i < wordlen; i++)
    {
        BSTInsert(&ARoot, word[i]);
    }
    InorderTraversal(ARoot);
    // Display level
    for (i = 0; i < wordlen; i++)
    {

        // Check if char has already been used
        BSTSearch(BRoot, word[i], &found, &TempPtr);

        if (!found)
        {
            level = BSTLevel(ARoot, word[i]);
            printf("\nLevel of %c: %d\n", word[i], level);
            BSTInsert(&BRoot, word[i]);
        }
    }

    return 0;
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
{
    return (Root == NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL)
    {
        Parent = LocPtr;
        if (Item < LocPtr->Data)
            LocPtr = LocPtr->LChild;
        else if (Item > LocPtr->Data)
            LocPtr = LocPtr->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("TO STOIXEIO EINAI HDH STO DDA\n");
    else
    {
        LocPtr = (BinTreePointer)malloc(sizeof(struct BinTreeNode));
        LocPtr->Data = Item;
        LocPtr->LChild = NULL;
        LocPtr->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item < Parent->Data)
            Parent->LChild = LocPtr;
        else
            Parent->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
               BinTreePointer *LocPtr)
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (KeyValue < (*LocPtr)->Data)
            (*LocPtr) = (*LocPtr)->LChild;
        else if (KeyValue > (*LocPtr)->Data)
            (*LocPtr) = (*LocPtr)->RChild;
        else
            (*Found) = TRUE;
    }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr, BinTreePointer *Parent)
{
    *LocPtr = Root;
    *Parent = NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (KeyValue < (*LocPtr)->Data)
        {
            *Parent = *LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else if (KeyValue > (*LocPtr)->Data)
        {
            *Parent = *LocPtr;
            *LocPtr = (*LocPtr)->RChild;
        }
        else
            *Found = TRUE;
    }
}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
{

    BinTreePointer
        n,
        Parent,
        nNext,
        SubTree;
    boolean Found;

    BSTSearch2(*Root, KeyValue, &Found, &n, &Parent);
    if (!Found)
        printf("TO STOIXEIO DEN EINAI STO DDA\n");
    else
    {
        if (n->LChild != NULL && n->RChild != NULL)
        {
            nNext = n->RChild;
            Parent = n;
            while (nNext->LChild != NULL) //* DIASXISH PROS TA ARISTERA *)
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
        if (Parent == NULL) //* 8A DIAGRAFEI H RIZA *)
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
    // Προσπέλαση από αριστερά προς
    // τα δεξία (αύξουσα σειρά)
    if (Root != NULL)
    {
        InorderTraversal(Root->LChild);
        printf("%c ", Root->Data);
        InorderTraversal(Root->RChild);
    }
}

int BSTLevel(BinTreePointer Root, BinTreeElementType Item)
{

    BinTreePointer LocPtr;
    int level, i;
    level = 1;
    LocPtr = Root;

    while (LocPtr != NULL)
    {

        if (Item < LocPtr->Data)
        {
            level++;
            LocPtr = LocPtr->LChild;
        }
        else if (Item > LocPtr->Data)
        {
            level++;
            LocPtr = LocPtr->RChild;
        }
        else
        {
            return level;
        }
    }
    return -1;
}
