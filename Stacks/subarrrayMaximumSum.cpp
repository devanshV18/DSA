#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

//brute force -> ignore
//works well
int sumSubarraymax(vector<int> v){
    int n = v.size();
    int sum = 0;

    for(int i = 0; i<n; i++){
        int maxi = v[i];
        for(int j = i; j<n; j++){
            maxi = max(maxi, v[j]);
            sum += maxi;
        }
    }
    return sum;
}

//optimal approach
//works well
//finding indices of next greater element 
vector<int> findNGE(vector<int> arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> findPGEE(vector<int> arr) {
        int n = arr.size();
        vector<int> pge(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

    int sumSubarrayMaximums(const vector<int> arr) {
    int n = arr.size();
    const int MOD = 1e9 + 7; 
    vector<int> pge = findPGEE(arr);
    vector<int> nge = findNGE(arr);
    int total = 0;

    for (int i = 0; i < n; i++) {
        // Number of subarrays where arr[i] is the maximum
        int left = i - pge[i]; // Count of subarrays ending to the left
        int right = nge[i] - i; // Count of subarrays starting to the right
        total = (total + (right * left * 1LL * arr[i]) % MOD) % MOD;
        } // Contribution to the sum

        return total;
    }

    


int main(){
    vector<int> test = {3,1,2,4};
    int ans = sumSubarraymax(test);
    cout << ans << endl;    
}