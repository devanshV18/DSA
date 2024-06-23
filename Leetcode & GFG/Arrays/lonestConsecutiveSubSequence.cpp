#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int longestSuccesiveSeq(vector<int> &nums){
    if(nums.size() == 0) return 0;

    sort(nums.begin(), nums.end());

    int n = nums.size();
    int lSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    for(int i = 0; i<n; i++){

        if(nums[i] - 1 == lSmaller){  //part of seq case
            cnt += 1;
            lSmaller = nums[i];
        }

        //nums[i] == lSmaller -> do nothing

        else if(nums[i] != lSmaller){
            cnt = 1;
            lSmaller = nums[i];
        }

        longest = max(cnt, longest);
    }

    return longest;
}



int main(){

}

