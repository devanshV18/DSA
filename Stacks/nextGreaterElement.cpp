#include<stack>
#include<vector>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE -> GOING TO EACH ELEMENT AND FINDING ITS NGE
vector<int> nge(vector<int> v){
    int n = v.size();
    vector<int> nge(n,-1);

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if( v[j] > v[i] ){
                nge[i] = v[j];
                break; // breaks the internal loop and goes to next iteration for outer loop.
            }
        }
    }

    return nge;
}


//OPTIMISED SOLUTION USING STACK
vector<int> nextGreaterElement(vector<int> v){
    int n = v.size();
    vector<int> nge(n);
    stack<int> s;

    //For each element in the array from right side as we need NEXT greater element
    for(int i = n-1; i>=0; i--){

        // upon reaching each element we check the stack for two conditions -> if stack is non empty and the top element is less than the current elemnt, in this case the top can never be the nge of the current element, Hece we pop the stack until stack has elements and top <= v[i] this ensures we pop until the stack gets empty => nge = -1 or until the top is not <= v[i] => nge = s.top()
        while( !s.empty() && s.top() <= v[i] ){
            s.pop();
        }

        //when popping stops 
        //check if popping stopped if the stack got empty
        if(s.empty()){
            nge[i] = -1;
        }

        //if popping stopped because top is no more <= v[i]
        else{
            nge[i] = s.top();
        }

        //we push each element in the stack
        s.push(v[i]);
    }

    return nge;
}

int main(){
    vector<int> inp = {6,0,8,1,3};
    vector<int> ans = nge(inp);

    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}