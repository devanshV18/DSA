#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

string subtract(string a, string b){
    //populating the set with chars of b
    unordered_set<char> charsInB(b.begin(), b.end());
    string result = "";
    for(int i =0; i<a.length(); i++){
        if(charsInB.find(a[i]) == charsInB.end()){ //if the char of string a is not present in the unordered_map that means those characters cant be deleted itself hence we add them to the result strign
            result += a[i];
        }
    }
    return result;
}

int main(){
    string A = "AABBCC";
    string B = "AB";
    string res = subtract(A,B);
    cout << res << endl;
}