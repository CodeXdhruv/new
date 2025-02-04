#include<iostream>
using namespace std;
#define MAX 400
int graph[MAX][MAX];
bool visited[MAX];
typedef struct{
    int items[MAX];
    int front,rear=0;
}Queue;

void initQueue(Queue* q){
    q->front=1;
    q->rear=-1;
}
bool isEmpty(Queue *q){
    return q->front==-1;
}
bool isFull(Queue *q){
    return q->rear==MAX-1;
}

void enqueue(Queue *q,int value){
    if(isFull(q)){
        cout<<"Queue is Full";
    }
    if(isEmpty(q)){
        q->front=0;
    }
    q->rear++;
    q->items[q->rear]=value;
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        cout<<"Queue is empty";
    }
    int d=q->items[q->front];
    if(q->front>=q->rear){
        q->front=-1;
        q->rear=-1;

    }
    else{
        q->front++;
    }
    return d;
}

void initGraph(int num_vertices){
    for(int i=0;i<num_vertices;i++){
        for (int j = 0; i < num_vertices; i++)
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
void bfs(int start_vertex,int num_vertices){
    Queue q;
    initQueue(&q);
    visited[start_vertex]=true;
    enqueue(&q,start_vertex);
    cout<<"BFS traversal is starting from "<<start_vertex<<endl;
    while(!isEmpty(&q)){
        int current_vertex=dequeue(&q);
        cout<<current_vertex;
        for(int i=0;i<num_vertices;i++){
            if(graph[current_vertex][i]==1 && !visited[i]){
                visited[i]=true;
                enqueue(&q,i);
            }
        }
    }
}

int main(){
    int vertices=5;
    initGraph(vertices);
    addedge(0,1);
    addedge(1,2);
    addedge(2,3);
    addedge(3,4);
    addedge(4,5);
    int start=0;
    bfs(start,vertices);
    return 0;
    
}
