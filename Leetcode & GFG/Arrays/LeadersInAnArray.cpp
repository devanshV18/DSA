#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> Leaders(vector<int> nums, int n){
    long long max = nums[n-1];
    vector<int> v;
    v.push_back(max);

    for(int i = n-2; i>=0; i--){

        if(nums[i] > max){
            max = nums[i];
            v.push_back(nums[i]);
        }
    }

    reverse(v.begin(),v.end());

    return v;


}