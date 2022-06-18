#include <stdio.h>
#include<string.h>

#define StackLimit 25

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
void GetNthElementA(StackType *Stack,int n, StackElementType *nelement);
void GetNthElementB(StackType *Stack,int n, StackElementType *nelement);

int main(){

    StackType S;
    CreateStack(&S);
    int i,n;
    StackElementType nItem;


    for(i=StackLimit*2;i>=2;i-=2){
        Push(&S,i);
    }
    TraverseStack(S);

    

    while (TRUE){
        printf("Dwse n: ");
        scanf(" %d",&n);
        if(n>=1 && n<=StackLimit)break;
    }
    GetNthElementA(&S,n,&nItem);
    printf("Top with GetNthElementA = %d",nItem);
    TraverseStack(S);
    GetNthElementB(&S,n,&nItem);
    printf("Top with GetNthElementB = %d",nItem);
    TraverseStack(S);
    


    return 0;
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
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}


void GetNthElementA(StackType *Stack,int n, StackElementType *nelement){


    StackType tempS;
    StackElementType item;

    int i ;

    CreateStack(&tempS);

    for(i=0;i<=StackLimit-n;i++){

        Pop(Stack,&item);
        Push(&tempS,item);
    }

    *nelement = item;

    while(!EmptyStack(tempS)){
        Pop(&tempS,&item);
        Push(Stack,item);
    }
   
}
void GetNthElementB(StackType *Stack,int n, StackElementType *nelement){
    *nelement = Stack->Element[n-1];
}