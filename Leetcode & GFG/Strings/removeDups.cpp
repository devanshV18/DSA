#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<map>

string removeDups(string s){
    map<char,int> fmap;
    string ans = "";

    for(int i = 0; i<s.length(); i++){
        if(fmap.find(s[i]) == fmap.end()){
            ans += s[i];
        }
        fmap[s[i]]++;
    }
    return ans;
}

int main(){
    string chk = "bcabc";
    string res = removeDups(chk);
    cout << res << endl;
}