#include<iostream>
using namespace std;

struct node{
    int data;
    int priority;
    struct node* next;
};

struct node* createNode(int value,int priority){
    struct node* node1=(struct node* )malloc(sizeof(struct node));
    node1->data=value;
    node1->priority=priority;
    node1->next=NULL;
}
void enqueue(struct node* head,int value,int priority){
    struct node* node1=createNode(value,priority);

    if(head==NULL||head->priority<priority){
        node1->next=head;
        head=node1;

    }
    struct node* temp=head;
    while(temp!=NULL && temp->next->priority<=priority){
        temp=temp->next;
    }
    node1->next=temp;
    temp->next=node1;
}
void dequeue(struct node* head){

    if(head==NULL){
        cout<<"Queue ois empty";
    }
    struct node* temp=head;
    head=head->next;
    delete temp;
}


int main(){

}