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
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                // the triplet combination
                if(nums[i] + nums[j] + nums[k] == 0 ) {
                    vector<int> temp = {nums[i], nums[j], nums[k]}; //formed a temporary triplet
                    sort(temp.begin(), temp.end()); //sorted the triplet to compare each triplet and all unique triplets are stored in the set
                    s.insert(temp); // the triplet temp is inserted in the set uniquely             
                }
            }
        }
    }

    vector<vector<int>> ans(s.begin(), s.end()); //the list of list stores all list (unique triplets) from set s into the ans list of lists 
    return ans; //return the answer simply.
}


//BETTER APPROACH -> HASHING : run two loops and eliminate the third loop by applying 2sum problem concept of target - (arr[i] + arr[j])

vector<vector<int>> threeSumBetter(vector<int> nums){
    int n = nums.size();
    set<vector<int>> s;

    for(int i = 0; i<n; i++){
        set<int> hashset; // we initiate an empty hashset as i moves or say for every new starting point i, as it subsequently updates j and hence both i and j moves, so a new hashset everytime i and j moves enables us to hash elements only between i and j thus avoiding any repeatition

        for(int j = i+1; j<n; j++){
            int third = -(nums[i] + nums[j]);
            if(hashset.find(third) != hashset.end()){
                //if third is in the hashset, we got a triplet
                vector<int> temp = { nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            //populate the hashset for every iteration
            hashset.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}


//OPTIMAL APPROACH
//eliominate the usage of set DS as we sort the array and we get all triplets in sorted order.
vector<vector<int>> threeSumOptimal(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i<n; i++){
            if( i>0 && nums[i] == nums[i-1]){
                continue;
            }
             int j = i+1;
             int k = n-1;

             while( j < k ){
                int sum = nums[i] + nums[j] + nums[k];
                if( sum < 0){
                    j++;
                }
                else if( sum > 0){
                    k--;
                }
                else{
                    //triplet is  0
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    if( j < k && nums[j] == nums[j-1]) j++;
                    if( j < k && nums[k] == nums[k+1]) k--;
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