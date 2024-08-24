#include<iostream>
#include<stack>
using namespace std;

bool isValid(string exp){
    stack<char> s;

    for(int i = 0; i< exp.length(); i++){
        
        char ch = exp[i];

        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }

        //closing bracket case
        else{
            //stack is not empty
            if(!s.empty()){
                char top = s.top();
                //we encounter a closing bracket and stack is not empty - checking for balancing
                if((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')
                  )
                {
                    s.pop();
                }
                //if we encounter a closing bracket but the matching doesn't fit
                else{
                    return false;
                }
            }
            //we encountered a closing bracket but the stack itself got empty - unbalanced expression
            else{
                return false;
            }
        }

        if(s.empty()){
            return true;
        }
        else{
            return false;
        }
    }
}