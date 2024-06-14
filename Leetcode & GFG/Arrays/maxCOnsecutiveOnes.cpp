#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int countConsecutives(vector<int> &bnums){
    int curr_count = 0;
    int max_count = 0;

    for(int i =0; i<bnums.size(); i++){
        if(bnums[i] == 1){
            curr_count++;
        }
        if(bnums[i] == 0){
            max_count = max(max_count,curr_count);
            curr_count = 0;
        }
    }

    if(curr_count > max_count){
        max_count = curr_count;
    }

    return max_count;
}