#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;
// const int MOD = 1e9 + 7;

//BRUTE FORCE
//works well

    int sumSubarrayMinimums(vector<int> v){
    int n = v.size();
    int maxSum = 0;
    for(int i = 0; i<n; i++){
        int mini = v[i];
        for(int j = i; j<n; j++){
            mini = min(mini, v[j]);
            maxSum += mini;
        }
    }
    return maxSum;
}






//OPTIMAL APPROACH USING NSE AND PSE
    //works well
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }


    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);
        int total = 0;
        for (int i = 0; i < arr.size(); i++) {
            int left = i - psee[i];
            int right = nse[i] - i;
            total = (total + (right * left * 1LL * arr[i]) % MOD) % MOD;
        }
        return total;
    }


int main() {
    vector<int> arr = {11,81,94,43,3};
    cout << "Sum of Subarray Minimums: " << subarrayMins(arr) << endl;
    return 0;
}