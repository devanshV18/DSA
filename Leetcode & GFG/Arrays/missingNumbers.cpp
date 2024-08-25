#include<iostream>
#include<vector>
using namespace std;

//Handles all cases - single or multiple

vector<int> missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> present(n+1, false);
        int m = present.size();

        for(int i = 0; i<n; i++){
            int curr = nums[i];
            present[curr] = true;
        }

        vector<int> missingNumbers;

        for(int i = 0; i<m; i++){
            if(!present[i]){
                missingNumbers.push_back(i);
            }
        }

        return missingNumbers;
    }

    //Mathematical approach

    int missingNumber(vector<int> nums){
        long long sum = 0;

        for(int i = 0; i<=nums.size(); i++){
            sum += i;
        }

        for(int i = 0; i<nums.size(); i++){
            sum -= nums[i];
        }

        return sum;
    }