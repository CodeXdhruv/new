// #include<iostream>
// using namespace std;
// #define MAX 100
// int graph[MAX][MAX];
// bool visited[MAX];
// typedef struct{
//     int items[MAX];
//     int front,rear;
// }Queue;
// void initQueue(Queue* q){
//     q->front=-1;
//     q->rear=-1;
// }
// bool isEmpty(Queue *q){
//     return q->front==-1;
// }
// bool isFull(Queue *q){
//     return q->rear==MAX-1;
// }
// void enqueue(Queue *q,int value){
//     if(isFull(q)){
//         cout<<"Queue is Full";
//     }
//     if(isEmpty(q)){
//         q->front=0;
//     }
//     q->rear++;
//     q->items[q->rear]=value;
// }
// int dequeue(Queue *q){
//     if(isEmpty(q)){
//         cout<<"Nothing to delete";
//         return -1;
//     }
//     int deq=q->items[q->front];
//     if(q->front>=q->rear){
//         q->front=-1;
//         q->rear=-1;
//     }
//     else{
//         q->front++;
//     }
//     return deq;
// }
// void initGraph(int num_vertices){
//     for(int i=0;i<num_vertices;i++){
//         for(int j=0;j<num_vertices;j++){
//             graph[i][j]=0;
//         }
//         visited[i]=false;
//     }
// }
// void addedge(int u,int v){
//     graph[u][v]=1;
//     graph[v][u]=1;
// }
// void bfs(int num_vertices,int start_vertex){
//     Queue q;
//     initQueue(&q);
//     visited[start_vertex]=true;
//     enqueue(&q,start_vertex);
//     // cout<<start_vertex<<" ";
//     while(!isEmpty(&q)){
//         int current_vertex=dequeue(&q);
//         cout<<current_vertex<<" ";
//         for(int i=0;i<num_vertices;i++){
//             if(graph[current_vertex][i]==1 && !visited[i]){
//                 visited[i]=true;
//                 enqueue(&q,i);
//             }
//         }
//     }
// }

// int main(){
//     int num_vertices=5;
//     initGraph(num_vertices);
//     addedge(0,1);
//     addedge(1,2);
//     addedge(2,3);
//     addedge(3,4);
//     // addedge(4,0);
//     int start=0;
//     bfs(num_vertices,start);
//     return 0;
// }

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
        return;
    }
    s->items[++s->top]=value;
}
int pop(Stack *s){
    if(isEmpty(s)){
        return -1;
    }
    int popp=s->items[s->top];
    s->top--;
    return popp;
}
void initGraph(int num_vertices){
    for(int i=0;i<num_vertices;i++){
        for (int j = 0; j < num_vertices; j++)
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

void dfs(int num_vertices,int start_vertex){
    Stack s;
    initStack(&s);
    push(&s,start_vertex);
    while(!isEmpty(&s)){
        int current_vertex=pop(&s);
        if(!visited[current_vertex]){
            visited[current_vertex]=true;
            cout<<current_vertex<<" ";
            for(int i=num_vertices-1;i>=0;i--){
                if(graph[current_vertex][i]==1 && !visited[i]){
                    push(&s,i);
                }
            }
        }
    }
}

int main(){
    int num_vertiex=5;
    initGraph(num_vertiex);
    addedge(0,1);
    addedge(1,2);
    addedge(2,3);
    addedge(3,4);
    int start=0;
    dfs(num_vertiex,start);
    return 0;
}