#include<vector>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sortColorsOrZOT(vector<int> nums){
    int l = 0;
    int i = 0;
    int r = nums.size() - 1;

    while(l <= r){
        if(nums[i] == 0){
            swap(nums[l],nums[i]);
            l++;
            i++;
        }
        else if(nums[i] == 2){
            swap(nums[r],nums[i]);
            r--;
        }
        else{
            i++;   //universal incrementation as it traverses the array
        }
    }
}