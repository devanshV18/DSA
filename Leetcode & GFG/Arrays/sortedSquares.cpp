#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

//brute force : -
// travesre and square them
//sort them using any function

vector<int> sortedSquares(vector<int> &nums){
    for(int i = 0; i<nums.size(); i++){
        nums[i] = nums[i] * nums[i];
    }
    sort(nums.begin(), nums.end());

    return nums;
}

//two pointer

vector<int> sortedSquares(vector<int> &nums){
    vector<int> res;

    for(int i = 0; i<nums.size(); i++){
        nums[i] = nums[i] * nums[i];
    }

    int head = 0;
    int tail = nums.size() - 1;
    for(int pos = nums.size() - 1; pos>=0; pos--){
        if(nums[head] > nums[tail]){
            res[pos] = nums[head];
            head++;
        }
        else{
            res[pos] = nums[tail];
            tail--;
        }
    }

    return res;

}