#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char BinTreeElementType; /*� ����� ��� ��������� ��� ���
                                    ���������� ����� int */
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
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);
int LeftNodeCount(BinTreePointer Root);

int main()
{
    char word1[] = "ALGORITHM";
    char word2[] = "MHTIROGLA";
    int i;

    BinTreePointer ARoot,
        BRoot;

    CreateBST(&ARoot);
    CreateBST(&BRoot);

    for (i = 0; i < strlen(word1); i++)
    {
        RecBSTInsert(&ARoot, word1[i]);
    }
    for (i = 0; i < strlen(word2); i++)
    {
        RecBSTInsert(&BRoot, word2[i]);
    }
    printf("First tree with inorder traverse\n");
    RecBSTInorder(ARoot);
    printf("\nSecond tree with inorder traverse\n");
    RecBSTInorder(BRoot);
    int nodes = LeftNodeCount(ARoot);
    printf("\nFirst tree LeftNodeCount = %d", nodes);
    printf("\nSecond tree LeftNodeCount = %d", LeftNodeCount(BRoot));

    return 0;
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
{
    return (Root == NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    if (BSTEmpty(*Root))
    {
        (*Root) = (BinTreePointer)malloc(sizeof(struct BinTreeNode));
        (*Root)->Data = Item;
        (*Root)->LChild = NULL;
        (*Root)->RChild = NULL;
    }
    else if (Item < (*Root)->Data)
        RecBSTInsert(&(*Root)->LChild, Item);
    else if (Item > (*Root)->Data)
        RecBSTInsert(&(*Root)->RChild, Item);
    else
        printf("TO STOIXEIO EINAI HDH STO DDA\n");
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                  boolean *Found, BinTreePointer *LocPtr)
{
    if (BSTEmpty(Root))
        *Found = FALSE;
    else if (KeyValue < Root->Data)
        RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
    else if (KeyValue > Root->Data)
        RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
    else
    {
        *Found = TRUE;
        *LocPtr = Root;
    }
}

void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)

{

    BinTreePointer TempPtr; //* true AN TO STOIXEIO KeyValue EINAI STOIXEIO TOY DDA *)

    if (BSTEmpty(*Root))
        printf("TO STOIXEIO DEN BRE8HKE STO DDA\n");
    else

        if (KeyValue < (*Root)->Data)
        RecBSTDelete(&((*Root)->LChild), KeyValue);
    else if (KeyValue > (*Root)->Data)
        RecBSTDelete(&((*Root)->RChild), KeyValue);
    else if ((*Root)->LChild == NULL)
    {
        TempPtr = *Root;
        *Root = (*Root)->RChild;
        free(TempPtr);
    }
    else if ((*Root)->RChild == NULL)
    {
        TempPtr = *Root;
        *Root = (*Root)->LChild;
        free(TempPtr);
    }
    else
    {

        TempPtr = (*Root)->RChild;
        while (TempPtr->LChild != NULL)
            TempPtr = TempPtr->LChild;

        (*Root)->Data = TempPtr->Data;
        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
    }
}

void RecBSTInorder(BinTreePointer Root)
{
    if (Root != NULL)
    {
        //    printf("L");
        RecBSTInorder(Root->LChild);
        printf("%c ", Root->Data);
        //    printf("R");
        RecBSTInorder(Root->RChild);
    }

    // printf("U");
}

void RecBSTPreorder(BinTreePointer Root)
{
    if (Root != NULL)
    {
        printf("%d ", Root->Data);
        // printf("L");
        RecBSTPreorder(Root->LChild);
        //  printf("R");
        RecBSTPreorder(Root->RChild);
    }
    // printf("U");
}

void RecBSTPostorder(BinTreePointer Root)
{
    if (Root != NULL)
    {
        //  printf("L");
        RecBSTPostorder(Root->LChild);
        //   printf("R");
        RecBSTPostorder(Root->RChild);
        printf("%d ", Root->Data);
    }
    // printf("U");
}

int LeftNodeCount(BinTreePointer Root)
{
    int lcount, rcount;
    lcount = 0;
    rcount = 0;
    if (BSTEmpty(Root))
    {
        return 0;
    }
    else
    {

        if (!BSTEmpty(Root->LChild))
        {
            lcount = LeftNodeCount(Root->LChild);
            lcount++;
        }
        if (!BSTEmpty(Root->RChild))
        {
            rcount = LeftNodeCount(Root->RChild);
        }
        return lcount + rcount;
    }
}
