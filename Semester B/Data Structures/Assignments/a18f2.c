#include <stdio.h>
#include<string.h>

#define StackLimit 6

typedef int StackElementType;

typedef struct {
    int Top;
    StackElementType Element[StackLimit];
} StackType; 

typedef enum { 

    FALSE, TRUE

}boolean;



void CreateStack(StackType *Stack);
void Push(StackType *Stack, StackElementType Item);
boolean FullStack(StackType Stack);
boolean EmptyStack(StackType Stack);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);



int main(){

    StackType S,minS;

    int i,min,item;
    
    CreateStack(&S);
    CreateStack(&minS);

    printf("Dwse to epomeno stoixeio: ");
    scanf(" %d",&item);
    Push(&S,item);
    Push(&minS,item);
    min = item;
    TraverseStack(S);
    printf("Min=%d\n",min);

    for(i=1;i<StackLimit;i++){

        printf("Dwse to epomeno stoixeio: ");
        scanf(" %d",&item);
        Push(&S,item);
        if(item<=min){

            Push(&minS,item);
            min = item;
        }
        TraverseStack(S);
        printf("Min=%d\n",min);
        
    }
    printf("\nEmptying Stack\n");

    while(!EmptyStack(S)){
        Pop(&S,&item);
        if(item==min){
            Pop(&minS,&item);
            if(!EmptyStack(minS)){
                Pop(&minS,&min);
                Push(&minS,min);
                printf("Min=%d\n",min);
            }
        }
        TraverseStack(S);
    }



    return 0 ;
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
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}