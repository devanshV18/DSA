#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string removeallexceptcharacters(string s){
    string res = "";
    for(int i = 0; i<s.length(); i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            res+=s[i];
        }
    }
    return res;
}

int main(){
    string a = "1.Python & 2.Java";
    string res = removeallexceptcharacters(a);
    cout << res << endl;
}