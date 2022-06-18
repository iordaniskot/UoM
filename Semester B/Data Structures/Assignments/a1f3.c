#include <stdio.h>
#include <string.h>

#define QueueLimit 21


typedef int QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum{
    FALSE, TRUE 
}boolean;



boolean EmptyQ(QueueType Queue);
void CreateQ(QueueType *Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);
int QSizeA(QueueType Q);
int QsizeB(QueueType *Q);

int main(){
    QueueType Q;
    QueueElementType temp;
    int i,qSize;
    // Question A
    CreateQ(&Q);
    for(i=0;i<QueueLimit-1;i++){
        AddQ(&Q,i);
    }
    printf("Question a\n");
    TraverseQ(Q);
    qSize = QSizeA(Q);
    printf("(QSizeA) size=%d\n",qSize);
    TraverseQ(Q);
    qSize = QsizeB(&Q);
    printf("(QSizeB) size=%d\n",qSize);
    TraverseQ(Q);
    // Question B
    printf("\n\nQuestion b\n");
    for(i=0;i<QueueLimit-1;i++){
        AddQ(&Q,i);
    }
    for(i=0;i<10;i++){
        RemoveQ(&Q,&temp);
    }
    TraverseQ(Q);
    qSize = QSizeA(Q);
    printf("(QSizeA) size=%d\n",qSize);
    TraverseQ(Q);
    qSize = QsizeB(&Q);
    printf("(QSizeB) size=%d\n",qSize);
    TraverseQ(Q);
    // Question C
    printf("\n\nQuestion c\n");
     qSize = QSizeA(Q);
    printf("(QSizeA) size=%d\n",qSize);
    TraverseQ(Q);
    qSize = QsizeB(&Q);
    printf("(QSizeB) size=%d\n",qSize);
    TraverseQ(Q);



    return 0;
}


boolean EmptyQ(QueueType Queue){
	return (Queue.Front == Queue.Rear);
}
void CreateQ(QueueType *Queue){
	Queue->Front = 0;
	Queue->Rear = 0;
}


boolean FullQ(QueueType Queue){
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item){
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item){
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue\n");
}

void TraverseQ(QueueType Queue){
	int current;
    printf("Printing Queue\n");
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear) {
             printf("%d ", Queue.Element[current]);
		  current = (current + 1) % QueueLimit;
	   }
	   printf("\n");
    }
    else printf("Empty Queue\n");
}

int QSizeA(QueueType Q){
    return (Q.Rear-Q.Front);
}

int QsizeB(QueueType *Q){
    int count=0;
    QueueElementType temp;
    while(!EmptyQ(*Q)){
        RemoveQ(Q,&temp);
        count++;
        
    }
    return count;
}