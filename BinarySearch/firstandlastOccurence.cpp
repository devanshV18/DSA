#include<iostream>
using namespace std;
#include<vector>

//brute force approach
//linear search

pair<int, int> firstAndLastOccurenceBrute(vector<int> v,int n, int x){
    int first = -1, last = -1;
    for(int i = 0; i<n; i++){
        if(v[i] == x){
            if(first == -1){
                first = i;
                last = i;
            }
            else{
                last = i;
            }
        }
    }
}


//optimal approach using lower bound and upper bound concepts

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

pair<int, int> firstAndLastOccurenceBound(vector<int> v, int n, int x){
    int lb = lowerBound(v,n,x);
    if(lb == n || arr[lb] != x) return {-1,-1};
     return {lb, upperBound(v,x,n)-1};
}


//optimal approach using plain binary search

pair<int, int> firstAndLastOccurencePlainBS(vector<int> v, int n, int x){
    int low = 0;
    int high = n-1;

    int first = -1, last = -1;

    while(low<high){
        int mid = low + (high-low)/2;

        if(v[mid] == x){
            first = mid;
            high = mid-1;
        }
        else if(v[mid] > x){
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }

    while(low<high){
        int mid = low + (high-low)/2;

        if(v[mid] == x){
            last = mid;
            low = mid + 1;
        }
        else if(v[mid] > x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return {first, last};
}