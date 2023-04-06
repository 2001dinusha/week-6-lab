#include<iostream>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

// Node structure for linked list
struct Node{
    int data;
    Node* next;
};

// Stack structure using linked list
struct Stack{
    Node* head; // head of the linked list
    Node* top; // top of the stack
    int size; // size of the stack
};

// Function to check if stack is empty
bool isEmpty(Stack s){
    if(s.top == NULL)
        return true;
    else
        return false;
}

// Function to check if stack is full
bool isFull(Stack s, int maxSize){
    if(s.size >= maxSize)
        return true;
    else
        return false;
}

// Function to create a new node with given data
Node* createNode(int x){
    Node* n = new Node;
    n->data = x;
    n->next = NULL;
    return n;
}

// Function to push an element onto the stack
void push(Stack& s, int x, int maxSize){
    if(isFull(s, maxSize)){
        cerr<<"Stack overflow"<<endl;
        exit(1);
    }
    Node* n = createNode(x);
    if(isEmpty(s)){ // stack is empty
        s.head = n; // new node is the head of the linked list
        s.top = n; // new node is also top
    }
    else{
        s.top->next = n;
        s.top = n;
    }
    s.size++;
}

// Function to pop an element from the stack
int pop(Stack& s){
    if(isEmpty(s)){
        cerr<<"Stack underflow"<<endl;
        exit(1);
    }
    else{
        int x = s.top->data;
        if(s.top == s.head){ // only one node
            s.top = NULL;
            s.head = NULL;
        }
        else{
            Node* tmp = s.head;
            while(tmp->next != s.top){ // iterating to the node previous to top
                tmp = tmp->next;
            }
            tmp->next = NULL; // making the next of the node null
            s.top = tmp; // changing the top pointer
        }
        s.size--;
        return x;
    }
}

// Function to display the elements in the stack
void display(Stack s){
    if(isEmpty(s)){
        cout<<"Stack is empty"<<endl;
        return;
    }
    Node* tmp = s.head;
    cout<<"Stack: ";
    while(tmp != NULL){
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

// Function to get the top element of the stack
int stackTop(Stack s){
    if(isEmpty(s)){
        cerr<<"Stack is empty"<<endl;
        exit(1);
    }
    return s.top->data;
}

// Driver code
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Node structure and stack methods...

int main(){
    Stack s;
    s.head = NULL;
    s.top = NULL;
    s.size = 0;

    int maxSize;
    cout<<"Enter maximum size of stack: ";
    cin>>maxSize;

    // Push 10 random values to the stack
     auto start = high_resolution_clock::now();
    srand(time(NULL));
    for (int i = 0; i < maxSize; i++) {
        int randomNum = rand() % 100 + 1; // Generate a random number between 1 and 100
        push(s, randomNum, maxSize);
    }

    // Pop 5 times
    for (int i = 0; i < maxSize; i++) {
        pop(s);
    }

    // Push 4 more random values to the stack
    for (int i = 0; i < 4; i++) {
        int randomNum = rand() % 100 + 1; // Generate a random number between 1 and 100
        push(s, randomNum, maxSize);
    }

    // Display the contents of the stack
    display(s);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    double duration_sec = duration.count() / 1000000.0; 

    cout << "Time taken by operations: " << fixed << setprecision(6) << duration_sec << " microseconds" << endl;

    return 0;
}
