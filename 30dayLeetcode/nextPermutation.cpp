#include<iostream>
using namespace std;
#include<vector>
#include<bits/stdc++.h>

 class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i = nums.size() - 1;

        while (i > 0 && nums[i-1] >= nums[i]){
            i--;
        }

        reverse(nums.begin() + i, nums.end());
        //cout << i;
        if (i == 0){
            return;
        }
        
        int j = i-1;
        while (1){
            if (nums[i] > nums[j]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                break;
            }else{
                i++;
            }
        }
    }
};