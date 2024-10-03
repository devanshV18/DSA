#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;

void allRepeaters(string s){
    map<char,int> m;
    for(int i = 0; i<s.length(); i++){
        m[s[i]]++;
    }

    for(auto it : m){
        if(it.second > 1){
            cout << it.first << " " << it.second << endl;
        }
    }

}

int main(){
    string chk;
    cout << "Please Enter Your Input String" << endl;
    cin >> chk;
    allRepeaters(chk);
}