#include<iostream>
using namespace std;

bool checkPalindrome(string str, int i, int j){
    //base case
    if(i>j){
        return true;
    }

    //solving one case
    if(str[i] != str[j]){
        
        return false;
    }

    else{
        return checkPalindrome(str,i+1,j-1);
    }
}

int main(){
    string str = "racecar";
    int res = checkPalindrome(str, 0, str.length()-1);
    cout<<res<<endl;
    cout<<"yo"<<endl;
}