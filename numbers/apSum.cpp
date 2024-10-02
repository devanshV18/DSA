#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int apsum(int a, int d, int n){
    return n/2 * (2*a + (n-1)*d);
}

int main(){
    int res = apsum(2,2,4);
    cout << res << endl;
}