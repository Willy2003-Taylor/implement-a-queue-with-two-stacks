#include<bits/stdc++.h>
using namespace std;
int n,x;
struct Stack{
    int *stack;
    int size;
    int top;
};

void stack_init(struct Stack *in, struct Stack *out, int n){
    in->size=n;
    in->stack=(int*)malloc(sizeof(int)*in->size);
    in->top=-1;

    out->size=n;
    out->stack=(int*)malloc(sizeof(int)*out->size);
    out->top=-1;
}

int stack_empty(struct Stack *s){
    if(s->top==-1)
        return 1;
    return 0;
}

void push(struct Stack *s, int x){
    if(s->top==s->size)
        printf("The stack overflows.");
    else{
        s->top++;
        s->stack[s->top]=x;
    }
}

int pop(struct Stack *s){
    if(stack_empty(s)){
        printf("The stack underflows.");
        return 0;
    }
    s->top--;
    return s->stack[s->top+1];
}

void enqueue(struct Stack *in,int x){
        push(in, x);
}

void dequeue(struct Stack *in, struct Stack *out){
    if(stack_empty(out)){
        while(!stack_empty(in)){
            push(out, in->stack[in->top]);
            break;
        }
    }
    for(int i=in->top-1;i>=0;i--)
        push(out,in->stack[i]);
}

int main(){
    struct Stack in;
    struct Stack out;
    scanf("%d",&n);
    stack_init(&in, &out, n);
    for(int i=0;i<n;i++){
        scanf("%d", &x);
        enqueue(&in, x);
    }
    printf("after enqueue: ");
    for(int i=0;i<=in.top;i++)
        printf("%d ",in.stack[i]);
    printf("\n");
    dequeue(&in, &out);
    printf("after dequeue: ");
    for(int i=0;i<=out.top;i++)
        printf("%d ",out.stack[i]);
    return 0;
}