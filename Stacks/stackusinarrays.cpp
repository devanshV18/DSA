#include<iostream>
using namespace std;

class Stack {
    public:
    int size;
    int *arr;
    int top;

    Stack(int s){
        this->size = s;
        top = -1;
        arr = new int[size];
    }

    void push(int value){
        //check for available space
        if(size - top > 1){
            top++;
            arr[top] = value;
        }
        else{
            cout << "Stack is Full - Stack Overflow" <<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack is empty - Stack Underflow" <<endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"Stack is empty" <<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top >= 0) {
            return false;
        }
        else{
            return true;
        }
    }
};

int main(){
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "The top element of stack is " << st.peek() <<endl;

    st.pop();

    cout << "The top element of stack is " << st.peek() <<endl;

    cout << "Is the Stack empty " << st.isEmpty() << endl;
}