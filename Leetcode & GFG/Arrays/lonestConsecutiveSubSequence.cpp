#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
#include<unordered_map>

//A fairly optimal solution

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

// A constarintly optimal solution : -

int longestSubsequence(vector<int> &numss){
    if(numss.size() == 0) return 0;

    int longest = 1;
    unordered_set<int> st;

    for(int i = 0; i<numss.size(); i++){
        st.insert(numss[i]);
    }

    for(auto it : st){
        if(st.find(it - 1) == st.end()){
            int count = 1;
            int x = it;

            while(st.find(x+1) != st.end()){
                x = x+1;
                count += 1;
            }

            longest = max(count,longest);
        }
        
    }

    return longest;
}



int main(){

}

