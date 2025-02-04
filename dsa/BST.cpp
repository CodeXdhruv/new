// #include<iostream>
// using namespace std;

// struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// };

// struct node* createNode(int value){
//     struct node* node1=(struct node*)malloc(sizeof(struct node));
//     node1->data=value;
//     node1->left=NULL;
//     node1->right=NULL;
// }

// struct node* insertNode(struct node* n,int value){
//     if(n==NULL){
//         n=createNode(value);
//         return n;
//     }
//     if(value>n->data){
//         return insertNode(n->right,value);
//     }
//     else{
//         return insertNode(n->left,value);
//     }
//     return n;

// }
// bool searchNode(struct node* n,int key){
//     //using recursion
//     // if(n==NULL){
//     //     return 0;
//     // }
//     // if(n->data==key){
//     //     return 1;
//     // }
//     // if(n->data<key){
//     //     searchNode(n->right,key);
//     // }
//     // else{

//     //     return searchNode(n->left,key);
//     // }
//     // using iterative way and optimised solution
//     struct node* temp=n;
//     while(temp!=NULL){
//         if(temp->data==key){
//             return true;
//         }
//         if(temp->data>key){
//             temp=temp->left;
//         }
//         else{
//             temp=temp->right;
//         }
//     }
//     return false;
    
// }

// int maxV(struct node* n){
//     struct node* temp=n;
//     while(temp->right!=NULL){
//         temp=temp->right;
//     }
//     return temp->data;
// }
// 
// struct node* deleteNode(struct node* n,int val){
//     if(n==NULL){
//         return n;
//     }
//     if(n->data==val){
//         //if no child
//         if(n->right==NULL && n->left==NULL){
//             delete n;
//             return NULL;
//         }
//         // if child at right is present
//         if(n->right!=NULL){
//             struct node* temp=n->right;
//             delete n;
//             return temp;
//         }
//         //if child at left is present
//         if(n->right==NULL){
//             struct node* temp=n->left;
//             delete n;
//             return temp;
//         }
//         // if both the lefT AND RIGHT childrena are present
//         if(n->left!=NULL && n->right!=NULL){
//             int mini=minV(n->right);
//             n->data=mini;
//             n->right=deleteNode(n->right,mini);
//             return n;
//         }
//     }
// }
// int main(){

// }

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;;
};

struct node* createNode(int value){
    struct node* node1=(struct node*)malloc(sizeof(struct node));
    node1->data=value;
    node1->left=NULL;
    node1->right=NULL;
}
struct node* insert(struct node* n,int value){
    if(n==NULL){
        return createNode(value);
    }
    if(value<n->data){
        n->left=insert(n->left,value);
    }
    if(value>n->data){
        n->right=insert(n->right,value);
    }
    return n;
}

struct node* search(struct node* n,int key){
    if(n==NULL ||n->data==key){
        return n;
    }
    if(key<n->data){
        search(n->left,key);
    }
    return search(n->right,key);    

}
struct node* minV(struct node* n){
    struct node* current=n;
    while(current!=NULL&&current->left!=NULL){
        current=current->left;
    }
    return current;
}
struct node* deleteNode(struct node* n,int key){
    if(n==NULL){
        return n;
    }
    if(n->data>key){
        n->left=deleteNode(n->left,key);
    }
    if(n->data<key){
        n->right=deleteNode(n->right,key);
    }
    else{
        if(n->left==NULL){
            struct node* temp=n->right;
            delete n;
            return temp;
        }
        if(n->right==NULL){
            struct node* temp=n->left;
            delete n;
            return temp;
        }
    }
    struct node* temp=minV(n->right);
    n->data=temp->data;
    n->right=deleteNode(n->right,temp->data);

}
void inorderTraversal(struct node* n){
    if(n!=NULL){
        inorderTraversal(n->left);
        cout<<n->data<<" ";
        inorderTraversal(n->right);
    }
}
int main(){
    struct node* n=NULL;
    int value;
    while(true){
        cin>>value;
        if(value%2==0){

            n=insert(n,value);
        }
        if(value==-1){
            break;
        }
    }
    cout<<endl;
    cout<<"inorderTraversal is ";
    inorderTraversal(n);
    cout<<endl;
    n=deleteNode(n,3);
    cout<<"inorderTraversal is ";
    inorderTraversal(n);

}