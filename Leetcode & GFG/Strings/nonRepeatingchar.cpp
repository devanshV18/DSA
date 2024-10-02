#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;


void nonRepeating(string s){
    unordered_map<char,int> m;
    for(int i = 0; i<s.length(); i++){
        m[s[i]]++;
    }
    for(auto it : m){
        if(it.second == 1){
            cout << it.first << " ";
        }
    }
}

int main(){
    string str = "google";
    nonRepeating(str);
}