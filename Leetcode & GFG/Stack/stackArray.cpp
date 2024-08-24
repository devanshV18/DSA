#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int top;
    int capacity;

    Stack(int size){
        arr = new int[size];
        top = -1;
        capacity = size;
    }

    //Destructor
    // ~Stack() {delete[] arr};

    void push(int val){
        if(top >= capacity){
            cout << "Stack Overflow" << endl;
        }
        top++;
        arr[top] = val;
    }

    void pop(){
        if(top == -1){
            cout << "Empty STack - Stack Underflow" << endl;
        }

        top = top - 1;
    }

    int top(){
        if(top == -1){
            cout << "Empty Stack - No Top Element available"<< endl;
            return -1;
        }
        return arr[top];
    }

    int size(){
        return top+1;
    }
};