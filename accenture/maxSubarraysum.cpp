#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<math.h>

using namespace std;

int maxSum(vector<int> v){
    int maxSum = INT_MIN;
    int sum = 0;
    for(int i = 0; i<v.size(); i++){
        sum += v[i];
        maxSum = max(maxSum,sum);
        if(sum < 0){
            sum = 0;
        }      
    }
    return maxSum;
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res = maxSum(nums);
    cout << res << endl;
}