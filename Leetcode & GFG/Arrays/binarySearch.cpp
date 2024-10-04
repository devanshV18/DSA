#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<vector>

int binarySearch(vector<int> v, int target){
    int low = 0;
    int high = v.size() - 1;
    while(low <= high){
        int mid = low + (high - mid)/2;
        if(v[mid] == target){
            return mid;
        }
        if(v[mid] > target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    vector<int> test = {1,3,5,7,9,11};
    int target = 11;
    int res = binarySearch(test,target);

    cout << res << endl;
}