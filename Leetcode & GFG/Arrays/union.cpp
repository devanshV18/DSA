#include<iostream>
#include<vector>
#include<set>
using namespace std;

//brute force 

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(arr1[i]);
        }
        for(int i = 0; i<m; i++){
            auto it = find(ans.begin(),ans.end(),arr2[i]);
            if(it == ans.end()){
                ans.push_back(arr2[i]);
            }
        }
        
        return ans;
    }
};

//optimised - using a set to avoid duplicates and then converting it to a vector is more efficient
//way

vector<int> findUnionOptimised(int arr1[], int arr2[], int n, int m)
    {

        set<int> unionSet;
        for(int i =0; i<n; i++){
            unionSet.insert(arr1[i]);
        }
        for(int i = 0; i<m; i++){
            unionSet.insert(arr2[i]); //inserts element of arr2 in set only if it is not there as set only takes unique value
        }

        vector<int> ans(unionSet.begin(),unionSet.end());

        return ans;

    }

