#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

#include <vector>
#include <algorithm> // for std::max

using namespace std;

//brute force

int trappedWater(vector<int> v) {
    int total = 0;
    int n = v.size();
    
    for (int i = 0; i < n; i++) {
        int lmax = 0;
        int rmax = 0;

        // Find the maximum height to the left of the current index
        for (int j = 0; j < i; j++) {
            lmax = max(lmax, v[j]);
        }

        // Find the maximum height to the right of the current index
        for (int k = i + 1; k < n; k++) {
            rmax = max(rmax, v[k]);
        }

        // Calculate trapped water at the current index
        if (lmax > v[i] && rmax > v[i]) {
            total += min(lmax, rmax) - v[i];
        }
    }

    return total;
}

//optimised

int trap(vector<int> v){

    //initialising required variables
    int n = v.size();
    int total = 0;
    vector<int> suffixMax(n);
    vector<int> prefixMax(n);
    
    
    //computing prefixmax array
    prefixMax[0] = v[0];
    for(int i = 1; i<n; i++){
        prefixMax[i] = max(prefixMax[i-1], v[i]);
    }

    //computing suffixmax array
    suffixMax[n-1] = v[n-1];
    for(int i = n - 2; i>=0; i--){
        suffixMax[i] = max(suffixMax[i+1], v[i]);
    }


    //computing the sum of water stored at each index
    for(int i = 0; i<n; i++){
        total = total + ( min(prefixMax[i], suffixMax[i]) - v[i] );
    }

    return total;
}

int main(){
    vector<int> test = {4,2,0,3,2,5};
    int res = trap(test);

    cout << res;
}