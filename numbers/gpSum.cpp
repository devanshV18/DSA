#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double gpSum(float a, float r, int n){
    float sum = 0;
    for(int i = 0; i<n; i++){
        sum = sum + a;
        a = a * r;
    }
    return sum;
}

int main() {
    float res = gpSum(1,0.5,3);
    cout << res << endl;
}
