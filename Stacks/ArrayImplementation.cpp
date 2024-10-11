#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int topIndex;
    int capacity;
    int * st;

    //CONSTRUCTOR
    Stack(int size){
        topIndex = -1;
        capacity = size;
        st = new int[size];
    }

    //DESTRUCTOR
    ~Stack() {delete[] st;}

    //PUSH
    void push(int x){
        if(topIndex >= capacity-1){
            cout << "The stack is full" << endl;
            return;
        }

        topIndex = topIndex + 1;
        st[topIndex] = x;
    }

    //POP
    void pop(){
        if(topIndex == -1){
            cout << "Stack is empty" << endl;
            return;
        }

        topIndex = topIndex - 1;
    }

    //TOP
    int top(){
        if(topIndex == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return st[topIndex];
    }

    // SIZE()
    int size(){
        return topIndex+1;
    }
};



int main(){
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top element: " << s.top() << endl;  // Should print 30
    cout << "Stack size: " << s.size() << endl;  // Should print 3

    s.pop();
    cout << "Top element after pop: " << s.top() << endl;  // Should print 20
    cout << "Stack size after pop: " << s.size() << endl;  // Should print 2

    s.push(40);
    cout << "Top element after push: " << s.top() << endl;  // Should print 40
    cout << "Stack size after push: " << s.size() << endl;  // Should print 3

    return 0;
}