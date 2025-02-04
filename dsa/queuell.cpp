#include<iostream>
using namespace std;


struct node{
    int data;
    struct node* next;
};
struct Queue{
    struct node* front;
    struct node* rear;
};
struct node* createNode(int value){
    struct node* node1= (struct node*)malloc(sizeof(struct node));
    node1->data=value;
    node1->next=NULL;
    return node1;
}
void initQueue(struct Queue* queue){
    queue->front=NULL;
    queue->rear=NULL;
}
int isEmpty(struct Queue* queue){
    return queue->front==NULL;
}
void enqueue(struct Queue* queue,int value){
    struct node* node1=createNode(value);
    if(queue->front==NULL && queue->rear==NULL){
        queue->front=node1;
        queue->rear=node1;
    }
    else{
        queue->rear->next=node1;
        queue->rear=node1;
    }
}
int Dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        cout<<"Queue is EMpty";
    }
    struct node* temp=queue->front;
    int pop=temp->data;
    queue->front->next=queue->front;
    if(queue->front==NULL){
        queue->rear=NULL;
    }
    delete temp;
    return pop;
}
void dispaly(struct Queue* queue){
    struct node* temp=queue->front;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    struct Queue queue;
    initQueue(&queue);
    int value;
    while(true){
        cin>>value;
        if(value==-1){
            break;
        }
        enqueue(&queue,value);
    }
    dispaly(&queue);


}