#include<iostream>
using namespace std;
#include<vector>


#include <unordered_map>
 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Declare an unordered map to store the numbers and their indices
        unordered_map<int, int> mp;
       
        // Loop through the array
        for(int i = 0; i < nums.size(); i++){
            // Check if the complement of the current number exists in the map
            if(mp.find(target - nums[i]) == mp.end())
                // If not, add the current number and its index to the map
                mp[nums[i]] = i;
            else
                // If yes, return the indices of the current number and its complement
                return {mp[target - nums[i]], i};
        }
 
        // If no pair is found, return {-1, -1} as a default value
        return {-1, -1};
    }
};
