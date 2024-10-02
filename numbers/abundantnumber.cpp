#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool abundant(int num){
    int divisorSum = 0;
    for(int i = 1; i<=num/2; i++){
        if(num % i == 0){
            divisorSum = divisorSum + i;
        }
    }
    cout << divisorSum << endl;
    if(divisorSum < num){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    bool res = abundant(18);
    cout << res << endl;
}