#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int value){
    struct node* node1=(struct node*)malloc(sizeof(struct node));
    node1->data=value;
    node1->next=NULL;
    return node1;
}
struct node* insertNode(struct node* head,int value){
    struct node* node1=createNode(value);
    if(head==NULL){
        return createNode(value);
    }
    head->next=node1;
    return node1;
}
struct node* deleteNode(struct node* head,int key){
    struct node* temp=head;
    for(int i=0;i<=key;i++){
        temp=temp->next;
    }
    

}

int main(){

}