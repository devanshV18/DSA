#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void changCase(string s){
    int n = s.length();
    for(int i = 0; i < n; i++){
        if((s[i] >= 'a' && s[i] <= 'z')){
            s[i] = toupper(s[i]);  // Use toupper() instead of towupper()
        }
        else if((s[i] >= 'A' && s[i] <= 'Z')){
            s[i] = tolower(s[i]);  // Use tolower() instead of towlower()
        }
    }

    cout << s << endl;
}

int main(){
    string a = "jAvA";
    changCase(a);  // Output will be "JaVa"
}
