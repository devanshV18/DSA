#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool strong(int num){
    int n = num;
    int cSum = 0;
    while(num > 0){
        int ld = num % 10;
        int val = 1;
        while(ld != 0){
            val = val*ld;
            ld--;
        }
        cSum = cSum + val;
        num = num / 10;
    }
    cout << cSum << endl;

    if(cSum == n){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    bool res = strong(145);
    cout << res << endl;
}