#include<iostream>
#include<vector>
using namespace std;

//finding next smaller inidces
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

//brute force, go to each line and find the maximum water it can store towards its right or left.
int maxWater(vector<int> v){

}