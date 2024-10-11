#include<stack>
#include<vector>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nge(vector<int> v){
    int n = v.size();
    vector<int> nge(n,-1);

    for( int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            if(v[j] > v[i]){
                nge[i] = v[j];
                break;
            }
        }
    }

    return nge;
}

vector<int> nextGreaterElement(vector<int> v){
    int n= v.size();
    vector<int> nge(n);
    stack<int> s;

    for(int i = n-1; i>=0; i--){
        while (!s.empty() && s.top() <= v[i]){
            s.pop();
        }

        if(s.empty()){
            nge[i] = -1;
        }
        else{
            nge[i] = s.top();
        }

        s.push(v[i]);
    }

    return nge;

}

int main(){
    vector<int> inp = {6,0,8,1,3};
    vector<int> ans = nextGreaterElement(inp);

    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}