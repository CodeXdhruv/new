#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
    int height;
};

struct node* createNode(int value) {
    struct node* node1 = (struct node*)malloc(sizeof(struct node));
    node1->data = value;
    node1->left = NULL;
    node1->right = NULL;
    node1->height = 1;
    return node1;
}

int getHeight(struct node* n) {
    return (n == NULL) ? 0 : n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int balancedFactor(struct node* n) {
    return (n == NULL) ? 0 : getHeight(n->left) - getHeight(n->right);
}

struct node* leftRotate(struct node* x) {
    struct node* y = x->right;
    struct node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

struct node* rightRotate(struct node* y) {
    struct node* x = y->left;
    struct node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

struct node* insertNode(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = balancedFactor(root);

    if (bf > 1 && value < root->left->data)
        return rightRotate(root);
    if (bf < -1 && value > root->right->data)
        return leftRotate(root);
    if (bf > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bf < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void levelOrderTraversal(struct node* root) {
    if (root == NULL)
        return;
    queue<struct node*> q;
    q.push(root);
    while (!q.empty()) {
        struct node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
    cout << "\n";
}

int main() {
    struct node* root = NULL;
    root = insertNode(root, 20);
    root = insertNode(root, 8);
    root = insertNode(root, 45);
    root = insertNode(root, 3);
    root = insertNode(root, 9);
    root = insertNode(root, 12);

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << "\nLevel-order traversal: ";
    levelOrderTraversal(root);

    return 0;
}
