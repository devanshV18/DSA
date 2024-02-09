#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

void solve(string str, string output,int index, vector<string>& ans){
    //base case;
    if(index>=str.length()){
        ans.push_back(output);
        return;
    }
    
    //inclusion
    char element = str[index];
    output.push_back(element);
    solve(str,output,index+1,ans);

    //exclusion
    solve(str,output,index+1,ans);




    
}

vector<string> subsequences(string str){
    vector<string> ans;
    string output;
    int index = 0;
    solve(str,output,index,ans);
}



int main(){
  
 }