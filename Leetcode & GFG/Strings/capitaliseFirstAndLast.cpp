#include<iostream>
#include<bits/stdc++.h>
#include<cctype>
#include<string>
using namespace std;

string captilaiseEnds(string &s){
   
    for(int i = 0; i<s.length(); i++){
        if( i == 0 || i == (s.length() - 1)){
            s[i] = toupper(s[i]);
        } 
        else if (s[i+1] == ' ' || s[i-1] == ' ') // Converting characters present before and after
        {
            s[i] = toupper(s[i]);
            // s[i] = toupper(s[i]);
        }
    }
    cout<<"String after capitalizing the first and last letter of each word of the string:" << "\n";
    return s;
    // cout << "The changes String: " << s << "\n";
}

int main(){
    string a;
    cout << "ENter your sentence" << endl;
    getline(cin, a);
    string res = captilaiseEnds(a);
    cout << res << endl;
}
