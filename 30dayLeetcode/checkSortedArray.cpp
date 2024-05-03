#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
     bool check(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        // if(nums[0] < nums[n-1])
        // return false;

        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1])
            cnt++;
        }

        if(cnt == 1 && nums[0] >= nums[n-1]) 
        return true;
        if(cnt == 0)
        return true;
        else
        return false;
    }
};