#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string reverse(string &s){
    int n = s.length();
    for(int i = 0; i<n/2; i++){
        swap(s[i], s[n-i-1]);
    }
    return s;
}

int main(){
    string str = "Hello";
    string res = reverse(str);
    cout << res << endl;
}