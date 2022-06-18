#include <stdio.h>
#include <string.h>
#include <stdlib.h>




typedef struct{
	char userid[9];
} QueueElementType;           

typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;


typedef enum{
    FALSE, TRUE
}boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void TraverseQ(QueueType Queue);

boolean search_for_userid(QueueElementType item);

int main(){

    QueueType Users,Admins;
	char choise = 'Y';
	QueuePointer CurrPtr;
	QueueElementType AnItem;
	int type; 
    boolean found;

	CreateQ(&Users);
	CreateQ(&Admins);

	while(choise =='Y'){

		printf("USERNAME: ");
		scanf(" %s",AnItem.userid);
		if(!search_for_userid(AnItem)){
			printf("Wrong user ID\n");
		}else{
			if(AnItem.userid[0]=='U'&&AnItem.userid[1]=='S'&&AnItem.userid[2]=='R'){
				CurrPtr = Users.Front;
                type = 0; // 0 == User, 1 == Admin
			}else{
                CurrPtr  = Admins.Front;
                type = 1;
            }

            
            if(type==0){ // Normal Users
                found = FALSE;
                while(CurrPtr!=NULL){
                    if(strcmp(CurrPtr->Data.userid,AnItem.userid)==0){
                        printf("You have logged in to the system from another terminal. New access is forbidden.\n");
                        found = TRUE;
                        break;
                    }else{
                        CurrPtr = CurrPtr->Next;
                    }
                }
                if(found==FALSE){
                    AddQ(&Users,AnItem);
                }
            }else{
                found = FALSE;
                while(CurrPtr!=NULL){
                    if(strcmp(CurrPtr->Data.userid,AnItem.userid)==0){
                        printf("You have logged in to the system from another terminal. New access is forbidden.\n");
                        found = TRUE;
                        break;
                    }else{
                        CurrPtr = CurrPtr->Next;
                    }
                }
                if(found==FALSE){
                    AddQ(&Admins,AnItem);
                }
            }
		}

		printf("New insertion Y/N (Y=yes, N=No)");
		scanf(" %c",&choise);
	}
    printf("Oura Diaxeiristwn\n");
    TraverseQ(Admins);
    printf("Oura Aplwn Xrhstwn\n");
    TraverseQ(Users);





    return 0;
}


void CreateQ(QueueType *Queue){
	(*Queue).Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue){
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item){
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item){
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}



void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%s \n", CurrPtr->Data.userid);
             CurrPtr = CurrPtr->Next;
        }
   }
    // printf("\n");
}



boolean search_for_userid(QueueElementType item){

    FILE *fp;
    char str[9];

	fp = fopen("I11F4.dat","r");
    if(fp==NULL){

        printf("PROBLEM OPENING FILE\n");
    }else{
        while(!feof(fp)){
            fscanf(fp,"%s",str);
			if(strcmp(str,item.userid)==0){
				fclose(fp);
				return TRUE;
			}
        }
    }
	fclose(fp);

	return FALSE;
}