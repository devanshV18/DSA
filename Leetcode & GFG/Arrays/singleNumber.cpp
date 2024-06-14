#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int singleNumber(vector<int> &nums){

    unordered_map<int,int> fmap;

    for(int i = 0; i<nums.size(); i++){
        fmap[nums[i]]++;
    }

    for(auto i = fmap.begin(); i!= fmap.end(); i++){
        if(i->second == 1){
            return i->first;
        }
    }

    return -1;
}