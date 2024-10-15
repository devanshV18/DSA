#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;
// const int MOD = 1e9 + 7;


//finding indices of nse for each element.
vector<int> findNSE(vector<int> arr){
    int n = arr.size();
    vector<int> nse(n);
    stack<int> s;

    for(int i=n-1; i>=0; i--){
        while( !s.empty() && arr[s.top()] >= arr[i] ){
            s.pop();
        }
        nse[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    return nse;
}


//finding pse indices for each element just with a edge case being handled that we check for smaller and equal element
vector<int> findPSEE(vector<int> arr){
    int n = arr.size();
    vector<int> pse(n);
    stack<int> s;

    for(int i = 0; i<n; i++){
        while( !s.empty() && arr[s.top()] > arr[i] ){
            s.pop();
        }
        pse[i] = s.empty() ? -1 : s.top();
    }
    return pse;
}

//finding subarray minsum using the logic
int subarrayMinSum(vector<int>& arr) {
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

int main(){
    vector<int> inp = {11,81,94,43,3};
    int ans = subarrayMinSum(inp);
    cout << ans << endl;
}