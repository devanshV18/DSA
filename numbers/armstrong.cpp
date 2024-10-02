#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isArmstrong(int num){
    int checkSum = 0;
    int k = to_string(num).length();
    int n = num;
    while(num > 0){
        int ld = num % 10;
        checkSum += pow(ld,k);
        num = num/10;
    }
    cout << checkSum << endl;
    if(checkSum == n){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n = 153;
    bool res = isArmstrong(n);
    cout << res << endl;
}