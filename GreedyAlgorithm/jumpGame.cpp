#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int> jumps){
    int finalPosn = jumps.size() - 1;

    for(int i = jumps.size() - 2; i>=0; i--){
          if(i+jumps[i] >= finalPosn){
            finalPosn = i;
          }
    }

    return finalPosn == 0;
}