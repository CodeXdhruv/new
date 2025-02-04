#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new node
struct node* createNode(int value) {
    struct node* node1 = new node();
    node1->data = value;
    node1->left = NULL;
    node1->right = NULL;
    return node1;
}

// Insert a node into the BST
struct node* insertNode(struct node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Search for a key in the BST
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key > root->data) {
        return search(root->right, key); // Add return here
    }
    return search(root->left, key);
}

// Find the node with the minimum value in the BST
struct node* minV(struct node* root) {
    struct node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

// Delete a node from the BST
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Case 1: Node with only a right child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 2: Node with only a left child
        else if (root->right == NULL) {
            struct node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Node with two children
        struct node* temp = minV(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal of the BST
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Main function to test the BST implementation
int main() {
    struct node* root = NULL;

    // Insert nodes into the BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    cout << "Inorder traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    // Search for a key in the BST
    int key = 40;
    struct node* found = search(root, key);
    if (found != NULL) {
        cout << "Key " << key << " found in the BST.\n";
    } else {
        cout << "Key " << key << " not found in the BST.\n";
    }

    // Delete a node from the BST
    cout << "Deleting node 50...\n";
    root = deleteNode(root, 50);

    cout << "Inorder traversal after deletion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
    