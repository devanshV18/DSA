#include<vector>
#include<set>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//brute force -> Finding all triplets and including the unique ones into the set and further into the 2d vector.

vector<vector<int>> threeSum(vector<int> nums){
    int n = nums.size();
    set<vector<int>> s;
    for(int i = 0; i<n; i++){
        for( int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}


//BETTER APPROACH -> HASHING : run two loops and eliminate the third loop by applying 2sum problem concept of target - (arr[i] + arr[j])

vector<vector<int>> threeSumBetter(vector<int> nums){
    int n = nums.size();
    set<vector<int>> s;

    for(int i = 0; i<n; i++){
        set<int> hashSet;
        for(int j = i+1; j<n; j++){
            int third = -(nums[i] + nums[j]);
            if(hashSet.find(third) != hashSet.end()){
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }

            hashSet.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}


//OPTIMAL APPROACH

vector<vector<int>> threeSumOptimal(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i<n; i++){
            if( i > 0 && nums[i] == nums[i-1] ){
                continue;
            }

            int j = i+1;
            int k = n-1;

            while( j < k ){
                int sum = nums[i] + nums[j] + nums[k];
                if( sum < 0 ){
                    j++;
                }
                else if( sum > 0 ){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while( j < k && nums[j] == nums[j-1] ){
                        j++;
                    }
                    while( j < k && nums[k] == nums[k+1] ){
                        k--;
                    }
                }
            }
        }
        return ans;
    }


int main(){
    vector<int> v = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSumOptimal(v);

    //printing a 2d array

   for(const auto& triplet : ans){
        cout << "[ ";
        for(int num : triplet) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << endl;
}