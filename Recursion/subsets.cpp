#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans){
    //base case 
    if(index>=nums.size()){
        ans.push_back(output);
        return;
    }

    //exclusion
    solve(nums,output,index+1,ans);

    //include
    int element = nums[index];
    output.push_back(element);
    solve(nums,output,index+1,ans);
    
}

vector<vector<int>> subsets(vector<int> nums){
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solve(nums,output,index,ans);
    return ans;
}



int main(){
    vector<int> numst = {1,2,3};
    

    for(int i=0;i<numst.size();i++){
        cout<<numst[i]<<" ";
    }

    
    vector<vector<int>> anst = subsets(numst);
    for(int j=0;j<anst.size();j++){
        cout<<anst[j]<<" ";
    }
 }