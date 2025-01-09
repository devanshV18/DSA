#include<iostream>
#include<vector>
using namespace std;


int modifiedBinarySearch(vector<int> v, int target, int left){
    if(left > right){
        return -1;
    }

    int mid = left + ((right - left) / 2 );
    
    if(v[mid] == target){
        return mid;
    }

    //handling the case if left part is sorted
    if(v[mid] >= v[left]){
        //if left part is sorted, we check if target is present in this part or not
        if(v[left] <= target && target <= v[mid]){
            return modifiedBinarySearch(v, target, left, mid-1);
        }
        else{
            return modifiedBinarySearch(v, target, mid+1, right);
        }
    }
    //if left part is not sorted, the below case executes as one part will always be sorted
    else{
        if(v[mid] <= target && target <= v[right]){
            return modifiedBinarySearch(v, target, mid+1, right);
        }
        else{
            return modifiedBinarySearch(v, target, left, mid-1);
        }
    }
}