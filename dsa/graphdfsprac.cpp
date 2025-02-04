#include<iostream>
using namespace std;
#define MAX 100
int graph[MAX][MAX];
bool visited[MAX];
typedef struct{
    int items[MAX];
    int top;
}Stack;
void initStack(Stack *s){
    s->top=-1;
}
bool isEmpty(Stack *s){
    return s->top==-1;
}
void push(Stack* s,int value){
    if(s->top==MAX-1){
        cout<<"Stack is Full";
    }
    s->items[++s->top]=value;
}
int pop(Stack *s){
    if(!isEmpty(s)){
        return -1;
    }
    int popp=s->items[s->top];
    s->top--;
    return popp;
}
void initGraph(int num_vertices){
    for(int i=0;i<num_vertices;i++){
        for (int j = 0; j < num_vertices; i++)
        {
            graph[i][j]=0;
        }
        visited[i]=false;
    }
}
void addedge(int u,int v){
    graph[u][v]=1;
    graph[v][u]=1;
    
}
void dfs(int num_vertices,int start_vertex)  {
    Stack s;
    initStack(&s);
    visited[start_vertex]=true;
    push(&s,start_vertex);
    cout<<"DFS traversal is starting from "<<start_vertex<<" ";
    while(!isEmpty(&s)){
        int current_vertex=pop(&s);
        // if(!visited[current_vertex]){
        //     visited[current_vertex]=true;
            cout<<current_vertex;
            for(int i=num_vertices;i>0;i--){
                if(graph[current_vertex][i]==1 && !visited[i]){
                    // visited[i]=true;
                    push(&s,i);
                }
            }
        }
    }


int main(){
    int num_vertices=5;
    initGraph(num_vertices);
    addedge(0,1);
    addedge(1,2);
    addedge(2,3);
    addedge(3,4);
    addedge(4,0);
    int start=0;
    dfs(num_vertices,start);
    return 0;
}