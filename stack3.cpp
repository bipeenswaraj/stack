#include<iostream>
#define size 10
using namespace std;

class Stack {
public:
    int data[size];
    int top;

    Stack() {
        top = -1;
    }

   
    void push(int val) {
        if (top >= size - 1) {
            cout << "Stack overloaded" << endl;
        } else {
            top++;
            data[top] = val;
        }
    }

    
    int pop() {
        if (top < 0) {
            cout << "Stack underflow" << endl;
            return -1; 
        } else {
            int val = data[top];
            top--;
            return val;
        }
    }

    
    bool isEmpty() {
        return top == -1;
    }

    
    void display() {
        cout << "Elements of the stack are:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << data[i] << endl;
        }
    }
};


class Array {
private:
    Stack stack1; // stack1
    Stack stack2; // stack2

public:
    
    void pushToStack1(int val) {
        stack1.push(val);
    }

   
    void popFromStack1ToStack2() {
        int val = stack1.pop();
        if (val != -1) { 
            stack2.push(val);
        }
    }

    
    void showstack1() {
        cout << "Elements of stack1 are:" << endl;
        stack1.display();
    }

    
    void showStack2() {
        cout << "Elements of stack2 are:" << endl;
        stack2.display();
    }

    void checkstack1Empty() {
        if (stack1.isEmpty()) {
            cout << "Stack1 is empty" << endl;
        } else {
            cout << "Stack1 is not empty" << endl;
        }
    }
};

int main() {
    Array arrayManager;

    int stack1[size] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10}; 

    arrayManager.checkstack1Empty();

   
    for (int i = 0; i < size; i++) {
        arrayManager.pushToStack1(stack1[i]);
    }

    arrayManager.showstack1();
    cout << "Transferring top elements from stack1 to stack2:" << endl;

    
    for (int i = 0; i < size; i++) {
        arrayManager.popFromStack1ToStack2();
    }

    arrayManager.showstack1(); 
    arrayManager.showStack2(); 

    return 0;
}
