#include<iostream>
using namespace std;

class TwoStack{
    int *arr;
    int size;
    int top1;
    int top2;

    TwoStack(int s){
        this->size = s;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    void push1(int value){
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = value;
        }
        else{
            cout << "Stack 1 is full" <<endl;
        }
    }

    void push2(int value){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = value;
        }
        else{
            cout << "Stack 2 is full" <<endl;
        }
    }

    //pop return the top of stack and removes it from stack
    int pop1(){
        if(top1>=0){
            int popval = arr[top1];
            top1--;
            return popval;
        }
        else{
            cout << "Stack Underflow - Stack is empty" <<endl;
        }
    }

    int pop2(){
        if(top2<size){
            int popval = arr[top2];
            top1++;
            return popval;
        }
        else{
            cout << "Stack Underflow - Stack is empty" <<endl;
        }
    }

};

int main(){
    
}