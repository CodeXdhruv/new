#include<iostream>
using namespace std;
#define MAX 100
int graph[MAX][MAX];
bool visited[MAX];
typedef struct{
    int items[MAX];
    int top;
}Stack;

void initStack(Stack* s){
    s->top=-1;
}
void isEmpty(Stack *s){
    return s->top==-1;
}
void isFull(Stack *s){
    return s->top==MAX-1;
}

void push(Stack *s,int value){
    if(isFull(s)){
        
    }
}