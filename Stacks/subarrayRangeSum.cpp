#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;


//BRUTE FORCE - WORKS WELL
int sumSubarrayRanges(vector<int> v){
    int n = v.size();
    int sum = 0;
    for(int i = 0; i<n; i++){
       int largest = v[i];
       int smallest = v[i];
       for(int j = i+1; j<n; j++){
        largest = max(largest, v[j]);
        smallest = min(smallest, v[j]);

        sum = sum + (largest - smallest);
       }
    }
    return sum;
}



//OPTIMAL APPROACH : -

// SUM OF SUB ARRAY RANGES = SUM OF SUBARRAY MAXIMUMS - SUM OF SUBARRAY MINIMUMS.








//SETUP TO FIND SUM OF SUBARRAY MINIMUMS : -
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











//SETUP TO FIND SUM OF SUBARRAY MAXIMUMS
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










//FINDING SUM OF SUBARRAY RANGES: - 

int sumOfSubArrayRanges(vector<int> v){
    int sumOfSubArrayminimums = sumSubarrayMins(v);
    int SumOfSubArraymaximums = sumSubarrayMaximums(v);

    int result = SumOfSubArraymaximums - sumOfSubArrayminimums;
    return result;
}








int main(){
    vector<int> test = {1,4,3,2};
    int ans = sumOfSubArrayRanges(test);

    cout << ans << endl;
}