#include<iostream>
#include<stack>
using namespace std;

//APPROACH 1 = SC == O(N)

class Stack{
    stack<pair<int, int>> s;

    void push(int val){
        if(s.empty()){
            s.push({val,val});
        }
        s.push({val, min(val,s.top().second)});
   }

};