#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std::chrono;
#define MAX_SIZE 3000

using namespace std;

class Stack {
    private:
        int top; // Index of the top element
        int arr[MAX_SIZE]; // Array to store elements
        int size; // Maximum size of the stack

    public:
        Stack(int size) {
            top = -1;
            this->size = size;
        }

        void push(int value) {
            top = top + 1;
            if (top > size) {
                cout << "Stack overflow!" << endl;
                top--;
                return;
            }
            arr[top] = value;
            //cout << value << " pushed into the stack." << endl;
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack underflow!" << endl;
                return -1;
            }
            int value = arr[top];
            top = top - 1;
            //cout << value << " popped from the stack." << endl;
            return value;
        }

        bool isEmpty() {
            return (top == -1);
        }

        bool isFull() {
            return (top == size - 1);
        }

        int stackTop() {
            if (isEmpty()) {
                cout << "Stack is empty!" << endl;
                return -1;
            }
            return arr[top];
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is empty!" << endl;
                return;
            }
            cout << "Elements in the stack: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;
    Stack s(size);
    auto start = chrono::high_resolution_clock::now();


    // Push 10 random values to the stack
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int value = rand() % 100;
        s.push(value);
    }

   // s.display();

    // Pop 5 elements from the stack
    for (int i = 0; i < size; i++) {
        s.pop();
    }

    // Push 4 random values to the stack
    for (int i = 0; i < 4; i++) {
        int value = rand() % 100;
        s.push(value);
    }

    s.display();

    
    auto end = chrono::high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    double duration_sec = duration.count() / 1000000.0; 

    cout << "Time taken by operations: " << fixed << setprecision(6) << duration_sec << " microseconds" << endl;

    return 0;
}
