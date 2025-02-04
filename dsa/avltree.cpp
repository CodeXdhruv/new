#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
    int height;
};

int getHeight(struct node* n) {
    if (n == NULL) {
        return 0;
    }
    return n->height;
}

int max(int a,int b){
    return a>b?a:b;
}

struct node* createNode(int value) {
    struct node* node1 = new node();
    node1->data = value;
    node1->left = NULL;
    node1->right = NULL;
    node1->height = 1;
    return node1;
}

int getBalancedFactor(struct node* n) {
    if (n == NULL) {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}
struct node* leftRotate(struct node* x){
    struct node* y=x->right;
    struct node* T2=y->left;

    y->left=x;
    x->right=T2;

    return y;
}

struct node* rightRotate(struct node* y){
    struct node* x=y->left;
    struct node* T2=x->right;

    x->right=y;
    y->left=T2;

    y->height=max(getHeight(y->right),getHeight(y->left))+1;
    x->height=max(getHeight(x->right),getHeight(x->left))+1;
    //returned x because x is now root node
    return x;

}



struct node* insertNode(struct node* root,int value){
    struct node* node1=createNode(value);
    if(root==NULL){
        return createNode(value);
    }
    if(value<root->data){
        root->left=insertNode(root->left,value);
    }
    else if(value>root->data){
        root->right=insertNode(root->right,value);
    }
    root->height=1+(max(getHeight(root->right),getHeight(root->left)));
    int bf=getBalancedFactor(root);
    //leftleft case
    if(bf>1 && value<root->left->data){
        return rightRotate(root);
    }
    
    //rightright case
    if(bf<-1 && value<root->right->data){
        return leftRotate(root);
    }
    //leftright case
    if(bf>1 && value>root->right->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    //rightleft case
    if(bf<-1 && value<root->right->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void preorderTraversal(struct node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
int main(){
    struct node* root=NULL;
    root=insertNode(root,45);
    root=insertNode(root,32);
    root=insertNode(root,6);
    root=insertNode(root,15);
    root=insertNode(root,4);
    preorderTraversal(root);

}