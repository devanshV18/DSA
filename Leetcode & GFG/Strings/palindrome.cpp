#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int n = s.length();
    for(int i = 0; i<n/2; i++){
        if(s[i] != s[n-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    string check = "ABCDCBA";
    bool res = isPalindrome(check);
    cout << res << endl;
}