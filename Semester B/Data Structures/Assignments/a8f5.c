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

boolean IdenticalBSTs(BinTreePointer Root1, BinTreePointer Root2);

int main()
{
    char word1[] = "IDENTICAL";
    char word2[] = "DIFFERENT";
    int i;

    BinTreePointer ARoot,
        BRoot, CRoot;
    CreateBST(&ARoot);
    CreateBST(&BRoot);
    CreateBST(&CRoot);

    for (i = 0; i < strlen(word1); i++)
    {
        RecBSTInsert(&ARoot, word1[i]);
        RecBSTInsert(&BRoot, word1[i]);
    }
    for (i = 0; i < strlen(word2); i++)
    {
        RecBSTInsert(&CRoot, word2[i]);
    }

    if (IdenticalBSTs(ARoot, BRoot))
    {
        printf("Ta dyadika dentra A kai B einai idia\n");
    }
    else
    {
        printf("Ta dyadika dentra A kai B diafferoun\n");
    }
    if (IdenticalBSTs(BRoot, CRoot))
    {
        printf("Ta dyadika dentra B kai C einai idia\n");
    }
    else
    {
        printf("Ta dyadika dentra B kai C diafferoun\n");
    }

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

boolean IdenticalBSTs(BinTreePointer Root1, BinTreePointer Root2)
{

    if (BSTEmpty(Root1) && BSTEmpty(Root2))
    {
        return TRUE;
    }
    else
    {
        if (!BSTEmpty(Root1) && !BSTEmpty(Root2))
        {

            return Root1->Data == Root2->Data && IdenticalBSTs(Root1->LChild, Root2->LChild) && IdenticalBSTs(Root1->RChild, Root2->RChild);
        }
        else
        {
            return FALSE;
        }
    }
}