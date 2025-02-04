#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value){
    struct node* node1=(struct node*)malloc(sizeof(struct node));
    node1->data=value;
    node1->left=NULL;
    node1->right=NULL;
    return node1;
}

void inorderTraversal(struct node* n){
    if(n!=NULL){
        inorderTraversal(n->left);
        cout<<n->data<<" ";
        inorderTraversal(n->right);
    }
}

void preorderTraversal(struct node* n){
    if(n!=NULL){
        cout<<n->data<<" ";
        
        preorderTraversal(n->left);
        preorderTraversal(n->right);
    }
}
void postorderTraversal(struct node* n){
    if(n!=NULL){
        postorderTraversal(n->left);
        postorderTraversal(n->right);
        cout<<n->data<<" ";
    }
}

struct node* minV(struct node* n){
    struct node* temp=n;
    while(temp && temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

struct node* maxV(struct node* n){
    struct node* temp=n;
    while(temp && temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
bool isBST(struct node* n){
    if(n==NULL){
        return true;
    }
    if(n->left!=NULL && maxV(n->left)->data>n->data){
        return false;
    }
    if(n->right!=NULL && minV(n->right)->data<n->data){
        return false;
    }
    return isBST(n->left) && isBST(n->right);
}


int main(){
    struct node* n=createNode(5);  
    n->left=createNode(4);
    n->left->left=createNode(3);
    n->right=createNode(8);
    n->right->right=createNode(15);

    cout<<"Inorder Traversal "<<endl;
    inorderTraversal(n);
    cout<<endl<<"Postorder Traversal "<<endl;
    postorderTraversal(n);
    cout<<endl<<"Preorder Traversal "<<endl;
    preorderTraversal(n);

    cout<<endl<<"Minimun element in the tree is "<<minV(n)->data;
    cout<<endl<<"Maximum element in the tree is "<<maxV(n)->data;
    cout<<endl;

    if(isBST(n)){
        cout<<"The tree is Binary search tree";
    }
    else{
        cout<<"The tree is not Binary search tree";
    }
}

