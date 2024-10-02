#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;

char solve(string s){
    if(s.length() == 0){
        return ' ';
    }
    map<char,int> m;
    int maxFreq = INT_MIN;
    for(int i = 0; i<s.length(); i++){
        m[s[i]]++;
        maxFreq = max(maxFreq, m[s[i]]);
    }

    for(auto it : m){
        if(it.second == maxFreq){
            return it.first;
        }
    }
    return ' ';
}

int main(){
    string s = "applle";
    char res = solve(s);
    cout << res << endl;
}