#include<iostream>
#include<bits/stdc++.h>
#include<set>
using namespace std;

string modifyy(string s, string t){
    set<char> se;
    for(int i = 0; i<t.length()-1; i++){
        se.insert(t[i]);
    }
    string ans = "";
    for(int i = 0; i<s.length()-1; i++){
        if(se.find(s[i]) == se.end()){
            ans += s[i];
        }
    }
    return ans;
}

int main(){
    string c1;
    cout << "Enter string to be modified" << endl;
    cin >> c1;

    string c2;
    cout << "Enter string to be referred" << endl;
    cin >> c2;

    string newString = modifyy(c1,c2);
    cout << newString << endl;
}