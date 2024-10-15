#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallerElementIndices(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return nse;
}

int main(){
    vector<int> test = {4,10,20,6,18,1};
    vector<int> nse = nextSmallerElementIndices(test);
    for(int i = 0; i< nse.size(); i++){
        cout << nse[i] << " ";
    }
}