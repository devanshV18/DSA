#include<iostream>
#include<vector>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE - 
vector<int> pge(vector<int> v){
    int n = v.size();
    vector<int> pge(n,-1);

    for(int i = 0; i<n; i++){
        for(int j = i-1; j>=0 ; j--){
            if(v[j] > v[i]){
                pge[i] = v[j];
                break;
            }
        }
    }
    return pge;
}


//Optimised Approach
vector<int> previousGreaterElement(vector<int> v){
    int n = v.size();
    vector<int> pge(n);
    stack<int> s;

    //SINCE WE NEED PREVIOUS greater elemnt the loop runs starts from left/start
    for(int i = 0; i<n; i++){
        while( !s.empty() && s.top() <= v[i]){
            s.pop();
        }

        if(s.empty()){
            pge[i] = -1;
        }
        else{
            pge[i] = s.top();
        }

        s.push(v[i]);
    }
    return pge;
}

int main(){
    vector<int> inp = {4,5,2,10,8};
    vector<int> ans = previousGreaterElement(inp);

    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " "; 
    }
    
    return 0;
}