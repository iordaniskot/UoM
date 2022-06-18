#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HMax 9

#define VMax 4
#define EndOfList -1

typedef struct
{
    char user_id[9];
    char password[7];

} ListElementType;
typedef int KeyType;

typedef struct
{
    KeyType key;
    ListElementType Data;
    int Link;
} ListElm;

typedef struct
{
    int HashTable[HMax];
    int Size;
    int SubListPtr;
    int StackPtr;
    ListElm List[VMax];
} HashListType;

typedef enum
{
    FALSE,
    TRUE
} boolean;

void CreateHashList(HashListType *HList);
int HashKey(KeyType key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList, KeyType KeyArg, int *Loc, int *Pred);
void SearchHashList(HashListType HList, KeyType KeyArg, int *Loc, int *Pred);
void AddRec(HashListType *HList, ListElm InRec);
void DeleteRec(HashListType *HList, KeyType DelKey);
void PrintPinakes(HashListType HList);
int foldKey(char s[]);
void BuildHashList(HashListType *HList);

int main()
{

    char ch;
    HashListType HList;
    ListElm AnItem;
    int Loc, Pred;

    BuildHashList(&HList);
    PrintPinakes(HList);

    while (TRUE)
    {

        printf("USERNAME: ");
        scanf(" %s", AnItem.Data.user_id);
        printf("PASSWORD: ");
        scanf(" %s", AnItem.Data.password);
        AnItem.key = foldKey(AnItem.Data.user_id);
        SearchHashList(HList, AnItem.key, &Loc, &Pred);

        if (Loc != -1)
        {

            if (strcmp(AnItem.Data.password, HList.List[Loc].Data.password) == 0)
            {
                printf("You have logged in to the sytsem\n");
            }
            else
            {
                printf("Access is forbidden: Wrong password\n");
            }
        }
        else
        {
            printf("Access is forbidden: Wrong user ID\n");
        }
        printf("Continue Y/N? ");
        scanf(" %c", &ch);
        if (ch == 'n' || ch == 'N')
        {
            break;
        }
    }

    return 0;
}

int HashKey(KeyType key)
{

    return key % HMax;
}

void CreateHashList(HashListType *HList)
{
    int index;

    HList->Size = 0;
    HList->StackPtr = 0;

    index = 0;
    while (index < HMax)
    {
        HList->HashTable[index] = EndOfList;
        index = index + 1;
    }

    index = 0;
    while (index < VMax - 1)
    {
        HList->List[index].Link = index + 1;
        index = index + 1;
    }
    HList->List[index].Link = EndOfList;
}

boolean FullHashList(HashListType HList)
{
    return (HList.Size == VMax);
}

void SearchSynonymList(HashListType HList, KeyType KeyArg, int *Loc, int *Pred)
{
    int Next;
    Next = HList.SubListPtr;
    *Loc = -1;
    *Pred = -1;
    while (Next != EndOfList)
    {
        if (HList.List[Next].key == KeyArg)
        {
            *Loc = Next;
            Next = EndOfList;
        }
        else
        {
            *Pred = Next;
            Next = HList.List[Next].Link;
        }
    }
}
void SearchHashList(HashListType HList, KeyType KeyArg, int *Loc, int *Pred)
{
    int HVal;
    HVal = HashKey(KeyArg);
    if (HList.HashTable[HVal] == EndOfList)
    {
        *Pred = -1;
        *Loc = -1;
    }
    else
    {
        HList.SubListPtr = HList.HashTable[HVal];
        SearchSynonymList(HList, KeyArg, Loc, Pred);
    }
}

void AddRec(HashListType *HList, ListElm InRec)

{
    int Loc, Pred, New, HVal;

    if (!(FullHashList(*HList)))
    {
        Loc = -1;
        Pred = -1;
        SearchHashList(*HList, InRec.key, &Loc, &Pred);
        if (Loc == -1)
        {
            HList->Size = HList->Size + 1;
            New = HList->StackPtr;
            HList->StackPtr = HList->List[New].Link;
            HList->List[New] = InRec;
            if (Pred == -1)
            {
                HVal = HashKey(InRec.key);
                HList->HashTable[HVal] = New;
                HList->List[New].Link = EndOfList;
            }
            else
            {
                HList->List[New].Link = HList->List[Pred].Link;
                HList->List[Pred].Link = New;
            }
        }

        else
        {
            printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
        }
    }
    else
    {
        printf("Full list...");
    }
}
void DeleteRec(HashListType *HList, KeyType DelKey)
{
    int Loc, Pred, HVal;

    SearchHashList(*HList, DelKey, &Loc, &Pred);
    if (Loc != -1)
    {
        if (Pred != -1)
        {
            HList->List[Pred].Link = HList->List[Loc].Link;
        }
        else
        {
            HVal = HashKey(DelKey);
            HList->HashTable[HVal] = HList->List[Loc].Link;
        }
        HList->List[Loc].Link = HList->StackPtr;
        HList->StackPtr = Loc;
        HList->Size = HList->Size - 1;
    }
    else
    {
        printf("DEN YPARXEI  EGGRAFH ME KLEIDI %d \n", DelKey);
    }
}

void PrintPinakes(HashListType HList)
{
    int i;
    printf("Hash table\n");
    for (i = 0; i < HMax; i++)
        printf("%d)%3d\n", i, HList.HashTable[i]);

    printf("Hash List\n");
    for (i = 0; i < VMax; i++)
        printf("%d)%3d,%12s,%9s,%4d\n", i, HList.List[i].key, HList.List[i].Data.user_id, HList.List[i].Data.password, HList.List[i].Link);
    printf("\n");
}

int foldKey(char s[])
{
    return (s[0] + s[strlen(s) - 1]) / 2;
}

void BuildHashList(HashListType *HList)
{
    ListElm AnItem;
    FILE *fp;

    CreateHashList(HList);

    fp = fopen("I5f6.txt", "r");

    if (fp == NULL)
    {
        printf("Problem opening file");
    }
    else
    {
        while (!feof(fp))
        {
            fscanf(fp, "%s\n", AnItem.Data.user_id);
            fscanf(fp, "%s\n", AnItem.Data.password);
            AnItem.key = foldKey(AnItem.Data.user_id);
            AddRec(HList, AnItem);
        }
        fclose(fp);
    }
}