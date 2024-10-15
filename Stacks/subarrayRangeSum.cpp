#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

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
// sum of sub array ranges = sum of subarray maximums - sum of subarray minimums.

int main(){
    vector<int> test = {1,4,3,2};
    int ans = sumSubarrayRanges(test);

    cout << ans << endl;
}