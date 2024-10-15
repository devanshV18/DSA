#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

vector<int> previousSmallerElementIndices(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    int main(){
        vector<int> test = {4,10,20,6,18,1};
    vector<int> nse = previousSmallerElementIndices(test);
    for(int i = 0; i< nse.size(); i++){
        cout << nse[i] << " ";
    }
    }