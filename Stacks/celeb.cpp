#include<iostream>
using namespace std;
#include<stack>
#include<vector>

int celeb(vector<vector<int>>& M,int n){
    stack<int> s;

    for(int i = 0; i<n; i++){
        s.push(i);
    }

    while(s.size()>1){
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(M[a][b] == 1){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int candidate = s.top();

    bool rowCheck = false;
    int zeroCount = 0;

    for(int i =0; i<n; i++){
        if(M[candidate][i]==0){
            zeroCount++;
        }
    }
    if(zeroCount==n){
        rowCheck = true;
    }

    bool colCheck = false;
    int oneCount = 0;

    for(int i =0; i<n; i++){
        if(M[i][candidate]==0){
            oneCount++;
        }
    }
    if(oneCount==n-1){
        colCheck = true;
    }


    if(rowCheck == true && colCheck == true){
        return candidate;
    }
    else{
        return -1;
    }
}