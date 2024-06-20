#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;



//The code for finding maximum subarray sum with a time complexity of O(N*N) : -
//THIS CODE WORKS FOR POSITIVES , POSITIVES + 0, POSITIVES + 0 + NEGATIVES BUT THIS CODE IS THE MOST OPTIMAL SOLUTION FOR CASES OF P + N + 0'S.

//WE HAVE AN OPTIMAL APPROACH BETTER THAN THIS BUT ONLY WORKS FOR POSITIVES + 0


int maximumSubArraySum(vector<int> nums, long long k){

    map<long long, int> preSum;

    int maxLen = 0;
    long long sum = 0;

    for(int i = 0; i<nums.size(); i++){
        sum += nums[i];

        if(nums[i] == k){
            maxLen = max(maxLen, i+1);
        }

        long long rem = sum - k;

        if(preSum.find(rem) != preSum.end()){
            int nLen = i - preSum[rem];

            maxLen = max(maxLen, nLen);
        }

        if(preSum.find(sum) == preSum.end()){
            preSum[sum] = i;
        }
    }

    return maxLen;
}


// Optimal solution for maximum sub array sum : -

int maximumSubArraySumOptimised(vector<int> v, long long k){
    int i = 0, j = 0;
    int n = v.size();
    int maxLen = 0;
    int sum = v[0];

    while(j < n){
        while(sum > k){
            sum -= v[i];
            i++;
        }

        if(sum == k){
            maxLen = max(maxLen, j-i+1);
        }

        j++;
        if(j < n) sum += v[j];
    }

    return maxLen;

}




int main(){

}