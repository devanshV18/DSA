#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int> nums, int target){
    unordered_map<int,int> m;

    for(int i = 0; i<nums.size(); i++){
        if(m.find(target-nums[i]) == m.end()){  //if required number is not in map
            m[nums[i]] = i; //populate map
        }
        else{ // required number is in map
            return {m[nums[i]],i};  // map - > val index  returns{index for the value target - nums[i] (required number) from the map, current index being traversed}
        }
    }

    return {-1,-1}; // in case no combination is found
}