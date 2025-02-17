#include<iostream>
using namespace std;
#include<vector>

//BRUTE FORCE -> Nested for loop[ linear search]

bool binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return true; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return false; // Target not found
}


//OPTIMAL SOLUTION 

//TC = O(N) + O(logN) = O(N) (As good as o(n))
bool searchInAMatrix(vector<vector<int>> &mat, int target){
    int m = mat.size();
    int n = mat[0].size();

    for(int i = 0; i<m; i++){
        if(target >= mat[i][0] && target <= mat[i][n-1]){
            return binarySearch(mat[i], target);
        }
    }

    return false;
}