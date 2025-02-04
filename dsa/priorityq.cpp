#include<iostream>
using namespace std;

struct node{
    int data;
    int priority;
    struct node* next;
};
struct node * createNode(int value,int priority){
    struct node* node1=(struct node* )malloc(sizeof(struct node*));
    node1->data=value;
    node1->priority=priority;
    node1->next=NULL;
    return node1;
}
void enqueue(struct node* head,int value,int priority){
    struct node* node1=createNode(value,priority);
    if(head==NULL || head->priority<priority){
        node1->next=head;
        head=node1;
    }
    else{
        struct node* temp=head;
        while(temp->next!=NULL && temp->next->priority<priority){
            temp=temp->next;
        }
        node1->next=temp->next;
        temp->next=node1;
    }
}
void dequeue(struct node* head){
    if(head==NULL){
        cout<<"Queue is empty";
    }
    struct node* temp =head;
    head=head->next;
    free(temp);
}
bool isEmpty(struct node* head){
    return head==NULL;
}
int main(){
    struct node *head=NULL;
    enqueue(&head,5,5);
}