#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int countWords(string s){
    int count = 0;
    for(int i = 0; i<s.length() - 1; i++){
        if(i != 0 && i != s.length() - 1){
            if(s[i] = ' '){
                count++;
            }
        }
    }
    return count+1;
}

int main(){
    string s;
    cin >> s;
    int count = countWords(s);
    cout << count << endl;
}