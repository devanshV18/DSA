#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int eqmIndex(vector<int> v){
    int n = v.size();
    for(int i = 0; i<n; i++){
        int lsum = 0;
        for(int j = 0; j<i; j++){
            lsum += v[j];
        }
        int rsum = 0;
        for(int k = i+1; k<n; k++){
            rsum += v[k];
        }

        if(lsum == rsum){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> a = {2,3,-1,8,4};
    int res = eqmIndex(a);
    cout << res << endl;
    
}