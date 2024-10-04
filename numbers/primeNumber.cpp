#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<math.h>



bool checkPrime(int num){
    if(num <= 1){
        return false;
    }
    int sqrtNum = sqrt(num);
    for(int i = 2; i<= sqrtNum; i++){
        if(num%i==0){
            return false;
        }
    }
    return true;

}

void checkInRange(int m, int n){
    for(int i = m; i<=n; i++){
        if(i<=n && checkPrime(i)){
            cout << i << " is a prime Number" << endl;
        }
    }
}

int main(){
    int m = 0, n = 10;
    checkInRange(m,n);
}