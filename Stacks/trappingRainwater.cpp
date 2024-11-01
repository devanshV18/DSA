#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

#include <vector>
#include <algorithm> // for std::max

using namespace std;

//brute force
// for each element lets find a lmax and rmax, lmax will be the maximum element from 0th index to the ith index while rmax will be maximum element from ith index to the last index. Therefore we calculate lmax and rmax for each elemnt or each index and at the end we check for one conmdition that if (lmax > v[i] && rmax > v[i]) if this holds true we have found a pge and an nge for ith index and water will be stored hence we update area using tha formula

int waterTrapped(vector<int> v){
    int n = v.size();
    int total = 0;

    for(int i = 0; i<n; i++){
        int lmax = 0;
        int rmax = 0;

        for(int j = 0; j<i; j++){
            lmax = max(lmax, v[j]);
        }

        for(int k = i+1; k<n; k++){
            rmax = max(rmax, v[k]);
        }

        if( lmax > v[i] && rmax > v[i] ){
            total = total + (min(lmax,rmax) - v[i]);
        }
    }

    return total;
}


// //optimised
// prefixMax stores the maximum elements from start till each index from the left.
// suffixMax stores the maximum element from last index till each insex from the right.
// therefore both arrays store tha pge, nge for each element in vector v.

int watertrap(vector<int> v){
    int n = v.size();
    vector<int> prefixMax(n);
    vector<int> suffixMax(n);
    int total = 0;

    //populating prefixMax array
    prefixMax[0] = v[0];
    for(int i = 1; i<n; i++){
        prefixMax[i] = max(prefixMax[i-1], v[i]);
    }

    
    suffixMax[n-1] = v[n-1];
    for(int j = n-1; j>=0; j--){
        suffixMax[j] = max(prefixMax[j+1], v[j]);
    }

    for(int k = 0; k<n; k++){
        total = total + ( min(prefixMax[k], suffixMax[k]) - v[k] );
    }

    return total;
}



int main(){
    vector<int> test = {4,2,0,3,2,5};
    int res = watertrap(test);

    cout << res;
}