#include<iostream>
using namespace std;
#include<stack>

void solve(stack<int>& inpStack, int count, int size){

    //base case
    if(count == size/2){
        inpStack.pop();
        return;
    }

    //Storing value for each RC
    int num = inpStack.top();
    inpStack.pop();

    //RC
    solve(inpStack,count+1,size);

    inpStack.push(num);
}

void deleteMid(stack<int> s,int n){
    int count = 0;
    solve(s,count,n);
}

int main(){

}