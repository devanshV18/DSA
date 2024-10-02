#include<iostream>
#include<bits/stdc++.h>
using namespace std;


string removeVowels(string &s){
    for(int i = 0; i<s.length(); i++){
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
        s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
    {
        s = s.substr(0,i) + s.substr(i+1);
        i--;
    }
}
return s;
}