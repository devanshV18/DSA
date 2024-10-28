#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;



//PROBLEM DESC - FIND THE SUBARRAY THAT HOLDS THE MAXIMUM PRODUCT AND RETURN THE PRODUCT.

//BRUTE FORCE : -

int maximumProductSubarray(vector<int> nums){
    int maxProduct = INT_MIN;
    for(int i = 0; i<nums.size(); i++){
        int eachSubarrayProduct = 1;
        for( int j = i; j<nums.size(); j++ ){
            eachSubarrayProduct = nums[j] * eachSubarrayProduct; // multiplying currrent eleement with the previous product of elements together forming current subarray
            maxProduct = max(maxProduct, eachSubarrayProduct);
        }
    }

    return maxProduct;
}



//OPTIMISED APPROACH - 
int maximumProductSubarrayOpt(vector<int> v){
    int pre = 1, suf = 1;
    int maxProduct = INT_MIN;
    int n = v.size();

    for( int i = 0; i<n; i++ ){
        if( pre == 0 ){
            pre = 1;
        }
        if( suf == 0 ){
            suf = 1;
        }        

        pre = pre * v[i];
        suf = suf * v[i];
        maxProduct = max( maxProduct, max(pre,suf) );
    }

    return maxProduct;
}


int main(){
    vector<int> v = {2,3,-2,4};
    int res = maximumProductSubarrayOpt(v);
    cout << res << endl;
}