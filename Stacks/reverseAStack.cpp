#include<iostream>
using namespace std;
#include<stack>


void insertAtBottom(stack<int> &s, int value){
    //base case
    if(s.empty()){
        s.push(value);
    }

    int num = s.top();
    s.pop();

    //RC
    insertAtBottom(s,value);
    s.push(num);                           
     
}

void reverse(stack<int> &stack){
    //base case
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    //RC
    reverse(stack);
    insertAtBottom(stack,num);
}

int main(){

}