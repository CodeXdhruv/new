// #include<iostream>
// using namespace std;
// #include<string>
// #define MAX 100
// struct Stack{
//     int top;
//     char arr[MAX];

// };
// void initStack(struct Stack* stack){
//     stack->top=-1;
// }
// bool isEmpty(struct Stack* stack){
//     return stack->top==-1;
// }
// bool isFull(struct Stack* stack){
//     return stack->top==MAX-1;
// }

// void push(struct Stack* stack,char value){
//     if(isFull(stack)){
//         cout<<"Stack is FUll";
//     }
//     stack->arr[++stack->top]=value;
// }

// char pop(struct Stack* stack){
//     if(isEmpty(stack)){
//         cout<<"Stack is Empty";
//     }
//     return stack->arr[stack->top--];
// }

// char peek(struct Stack* stack){
//     if(isEmpty(stack)){
//         cout<<"Stack is empty";
//     }
//     return stack->arr[stack->top];
// }

// int main(){
//     struct Stack stack;
//     initStack(&stack);

//     string str;
//     getline(cin,str);

//     for(int i=0;i<str.length();i++){
//         push(&stack,str[i]);
//     }
    
//     cout<<"Reversed string is ";
//     for(int i=0;i<str.length();i++){
//         pop(&stack);
//         cout<<" ";
//     }

 
// }

// #include<iostream>
// using namespace std;
// #include<string>
// #define MAX 100
// struct Stack{
//     int top;
//     char arr[MAX];

// };
// void initStack(struct Stack* stack){
//     stack->top=-1;
// }
// bool isEmpty(struct Stack* stack){
//     return stack->top==-1;
// }
// bool isFull(struct Stack* stack){
//     return stack->top==MAX-1;
// }

// void push(struct Stack* stack,char value){
//     if(isFull(stack)){
//         cout<<"Stack is FUll";
//     }
//     stack->arr[++stack->top]=value;
// }

// char pop(struct Stack* stack){
//     if(isEmpty(stack)){
//         cout<<"Stack is Empty";
//     }
//     return stack->arr[stack->top--];
// }

// char peek(struct Stack* stack){
//     if(isEmpty(stack)){
//         cout<<"Stack is empty";
//     }
//     return stack->arr[stack->top];
// }

// int main(){
//     struct Stack stack;
//     initStack(&stack);

//     string str;
//     getline(cin,str);

//     for(int i=0;i<str.length();i++){
//         push(&stack,str[i]);
//     }
    
//    for(int i=stack.top;i>=0;i++){
//         cout<<stack.arr[i];
//    }
 
// }
#include <iostream>
using namespace std;

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(Stack* stack) {
    stack->top = -1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

void push(Stack* stack, int data) {
    if (isFull(stack)) {
        cout << "Stack overflow! Cannot push " << data << endl;
        return;
    }
    stack->arr[++stack->top] = data;
    cout << data << " pushed to stack" << endl;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Stack underflow! Cannot pop" << endl;
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return stack->arr[stack->top];
}

int main() {
    Stack stack;
    initStack(&stack);
    int n;
    int count=0;
    for(int i=1;i<5;i++){
        cin>>n;
        push(&stack,n);
        count++;
    }

    for(int i=0;i<=5)

    

    return 0;
}