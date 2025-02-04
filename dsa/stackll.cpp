#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};
struct Stack{
    struct node* top;
};

struct node* createNode(int value){
    struct node* node1=(struct node*)malloc(sizeof(struct node));
    node1->next=NULL;
    node1->data=value;
    return node1;
}
struct Stack* createStack(){
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct node));
    stack->top=NULL;
    return stack;
}
int isEmpty(struct Stack* stack){
    return stack->top==NULL;
}

void push(struct Stack* stack,int value){
    struct node* node1=createNode(value);
    node1->next=stack->top;
    stack->top=node1;
    cout<<"Value pushed is "<<value;
}

int pop(struct Stack* stack){
    if(isEmpty(stack)){
        cout<<"Stack is EMpty";
    }
    struct node* temp=stack->top;
    int popp=temp->data;
    stack->top=stack->top->next;
    delete temp;
    return popp;
}

void display(struct Stack* stack) {
    // if(stack->top==NULL){
    //     return;
    // }
    struct node* temp = stack->top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    struct Stack stack;
    int value;
    while(true){
        cin>>value;
        if(value==-1){
            break;
        }
        push(&stack,value);
    }
    // cout<<"Value popped is "<<pop(&stack);
    display(&stack);
}
#include <iostream>
using namespace std;

// Define the structure for a Node in the linked list
struct Node {
    int data;   // Holds the data (customer's ID)
    Node* next; // Pointer to the next node in the list
};

// Define the structure for a Stack using linked list
struct Stack {
    Node* top; // Pointer to the top of the stack

    // Constructor to initialize the stack (top is nullptr initially)
    Stack() {
        top = nullptr;
    }

    // Function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node();  // Create a new node
        newNode->data = value;       // Assign data
        newNode->next = top;         // New node points to the current top
        top = newNode;               // Update top to the new node
        cout << "Value pushed: " << value << endl;
    }

    // Function to pop an element from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow! Cannot pop from an empty stack.\n";
            return;
        }
        Node* temp = top;    // Temporary pointer to the top node
        top = top->next;     // Move top to the next node
        cout << "Value popped: " << temp->data << endl;
        delete temp;         // Free memory of the popped node
    }

    // Function to display all elements in the stack
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;    // Start from the top node
        while (temp != nullptr) {
            cout << temp->data << " "; // Print data of the node
            temp = temp->next;         // Move to the next node
        }
        cout << endl;
    }

    // Destructor to clean up all nodes (free memory)
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp; // Delete each node
        }
    }
};

int main() {
    Stack stack; // Create a stack
    int choice, value;

    while (true) {
        cout << "\nEnter 1 to Push, 2 to Pop, 3 to Display, -1 to Exit: ";
        cin >> choice;

        if (choice == -1)
            break;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);  // Push value onto stack
                break;
            case 2:
                stack.pop();  // Pop value from stack
                break;
            case 3:
                cout << "Stack contents: ";
                stack.display();  // Display stack contents
                break;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}