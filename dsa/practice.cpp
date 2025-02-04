#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

struct node* createNode(int value){
    struct node* node1=(struct node*)malloc(sizeof(struct node));
    node1->data=value;
    node1->left=NULL;
    node1->right=NULL;
    node1->height=1;
    return node1;
}
int max(int a,int b){
    return a>b?a:b;
}

int getHeight(struct node* n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}
int getBalancedFactor(struct node* n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left)-getHeight(n->right);
}
struct node* leftRotation(struct node* x){
    struct node* y=x->right;
    struct node* T2= y->left;

    y->left=x;
    x->right=T2;

    y->height=max(getHeight(y->right),getHeight(y->left));
    x->height=max(getHeight(x->right),getHeight(x->left));

    return y;

}
struct node* rightRotate(struct node* y){
    struct node* x=y->left;
    struct node* T2=x->right;

    x->right=y;
    y->left=T2;

    y->height=max(getHeight(y->right),getHeight(y->left))+1;
    x->height=max(getHeight(x->right),getHeight(x->left))+1;
    return x;
}

struct node* insertNode(struct node* root,int value){
    struct node* node1=createNode(value);

    if(root==NULL){
        return createNode(value);
    }
    if(root->data<value){
        root->right=insertNode(root->right,value);
    }
    if(root->data>value){
        root->left=insertNode(root->left,value);
    }
    int bf=getBalancedFactor(root);
    //leftleft case
    if(bf>1){
        return rightRotate(root);
    }
    //rightright case
    if(bf<-1 && root->data<value){
        return leftRotation(root);
    }
    //leftright case
    if(bf>1 && root->data<value){
        root->left=rightRotate(root->left);
        return leftRotation(root);
    }
    //rightleft case
    if(bf<-1 && root->data>value){
        root->right=leftRotation(root->right);
        return rightRotate(root);
    }
    return root;
}
void inorderTraversal(struct node* root){
    if(root!=NULL){
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
}

int main(){
    struct node* root=NULL;
    root=insertNode(root,5);
    root=insertNode(root,6);
    root=insertNode(root,4);
    root=insertNode(root,32);
    root=insertNode(root,50);
    inorderTraversal(root);
}