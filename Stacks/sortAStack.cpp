#include<iostream>
using namespace std;
#include<stack>


void sortedInsert(stack<int> &s, int value){
    //base case
    if(s.empty() || (!s.empty() && s.top() < value)){
        s.push(value);
        return;
    }

    int num = s.top();
    s.pop();

    //RC
    sortedInsert(s,value);
    s.push(num);
}

void sort(stack<int> &stack){
    //base case
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    //RC
    sort(stack);
    //backtrack call
    sortedInsert(stack,num);
}


int main(){

}

