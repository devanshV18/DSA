#include<iostream>
#include<vector>
using namespace std;

void strReplacement(string &str){
    for(int i = 0; i<str.length(); i++){
        if(str[i] == 'a'){
            str[i] = 'b';
        }
        else if(str[i] == 'b'){
            str[i] = 'a';
        }
    }
}

int main(){
    string a = "abaabbcc";
    strReplacement(a);
    cout<<a<<endl;
}