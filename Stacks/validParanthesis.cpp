#include<iostream>
using namespace std;
#include<stack>


bool validParanthesis(string exp){
    stack<char> s;

    for(int i=0; i<exp.length(); i++){

        char ch = exp[i];
        if(ch=='('|| ch=='{'||ch=='['){
            s.push(ch);
        }

        else{ // closing brackets
            char top = s.top();
           
           if(!s.empty()){
             if(
                (ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')
              ){
                s.pop();
              }
              else{
                return false;
              }
           }

           else{
            return false;
           }
        }
    }

    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){

}