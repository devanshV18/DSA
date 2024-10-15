#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;


vector<int> nextGreaterElementByIndices(vector<int> arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return nge;
    }

int main(){
    vector<int> test = {4,10,20,6,18,1};
    vector<int> nse = nextGreaterElementByIndices(test);
    for(int i = 0; i< nse.size(); i++){
        cout << nse[i] << " ";
    }
}