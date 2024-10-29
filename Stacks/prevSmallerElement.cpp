#include<iostream>
#include<vector>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE - 
vector<int> pse(vector<int> v){
    int n = v.size();
    vector<int> pse(n,-1);

    for(int i = 0; i<n; i++){
        for(int j = i-1; j>=0; j--){
            if( v[j] < v[i] ){
                pse[i] = v[j];
                break;
            }
        }
    }

    return pse;
}


//Optimised Approach
vector<int> previousSmallerELement(vector<int> v){
    int n = v.size();
    vector<int> pse(n);
    stack<int> s;

    for(int i = 0; i<n; i++){
        while(!s.empty() && s.top() >= v[i]){
            s.pop();
        }

        if(s.empty()){
            pse[i] = -1;
        }
        else{
            pse[i] = s.top();
        }

        s.push(v[i]);
    }

    return pse;
}

int main(){
    vector<int> inp = {4,5,2,10,8};
    vector<int> ans = previousSmallerELement(inp);

    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " "; 
    }
    
    return 0;
}