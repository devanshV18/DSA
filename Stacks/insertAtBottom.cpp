#include<iostream>
using namespace std;
#include<stack>

//a function which changes the argumented stack and returns the modified stack
void solve(stack<int>& s, int num){
    //base case
    if(s.empty()){
        s.push(num);
        return;
    }

    //storing the backrtracking value
    int store = s.top();
    s.pop();

    //RC
    solve(s,num);
    s.push(store);
}

stack<int> insertAtBottom(stack<int>& myStack, int x){
    solve(myStack,x);
    return myStack;
}


int main(){

}