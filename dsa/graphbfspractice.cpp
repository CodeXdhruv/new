#include<iostream>
using namespace std;

#define MAX 100
int graph[MAX][MAX];
bool visited[100];

typedef struct{
    int items[MAX];
    int front,rear;
}Queue;

void initQueue(Queue* q){
    q->front=-1;
    q->rear=-1;
}
bool isEmpty(Queue *q){
    return q->front==-1; 
}
bool isFull(Queue *q){
    return q->rear==MAX-1;
}
void enqueue(Queue* q,int value){
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
        cout<<"Queue is Empty";
    }
    int dequeueElement=q->items[q->front];
    if(q->front>=q->rear){
        q->front=-1;
        q->rear=-1;
    }
    else{
        q->front++;
    }
    return dequeueElement;
}
void initGraph(int num_vertices){
    for(int i=0;i<num_vertices;i++){
        for(int j=0;j<num_vertices;j++){
            graph[i][j]=0;
        }
        visited[i]=false;
    }

}
void addedge(int u,int v){
    graph[u][v]=1;
    graph[v][u]=1;
}
void bfs(int num_vertices,int start_vertex){
    Queue q;
    initQueue(&q);
    visited[start_vertex]=true;
    enqueue(&q,start_vertex);
    // cout<<"Bfs traversal is starting from "<<start_vertex;
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
void warshallAlgo(int n,int graph[MAX][MAX]){
    int reach[MAX][MAX],i,j,k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            reach[i][j]=graph[i][j];        }
    }

    for(int k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;i<n;j++){
                reach[i][j]=reach[i][j] || reach[i][k] && reach[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(j=0;j<n;j++){
               
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
    addedge(4,0);
    int start=0;
    bfs(vertices,start);
}