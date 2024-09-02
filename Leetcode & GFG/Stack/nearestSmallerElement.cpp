#include<vector>
#include<iostream>
#include<stack>
using namespace std;


//Naive Brute Force Approach 
// TC -> O(N^2)
// SC -> O(N)

vector<int> nse(vector<int> &nums){
    int n = nums.size();
    vector<int> nse(n,-1);
    for(int i = 0; i<n-1; i++){
        for(int j = i-1; j>=0; j--){
            if(nums[j] < nums[i]){
                nse[i] = nums[j];
                break;
            }
        }
    }
    return nse;
}