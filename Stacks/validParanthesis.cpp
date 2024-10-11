#include<iostream>
using namespace std;
#include<stack>


bool validParanthesis(string exp){
    stack<char> st;

    for(int i = 0; i<exp.length(); i++){

      //opening brackets
      if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
        st.push(exp[i]);
      }

      //closing brackets
      else{ 
        
        //closing bracket encountered but stack got empty
        if(st.empty()){
          return false;
        }

        //closing bracket but stack is not empty
        char c = st.top();
        
        //if combination matched -> pop and move futher in the iteration
        if( ( exp[i] == ')' && c == '(' ) || ( exp[i] == '}' && c == '{' ) || ( exp[i] == ']' && c == '[' ) ){
          st.pop();
        }

        //if a mismatch occurs -> return false
        else{
          return false;
        }
      
      }
    }

    //after the complete string is iterated

    //check if stack is empty
    if(st.empty()){
      return true;
    }

    else{
      return false;
    }
}

int main(){
  string s;
  cin >> s;
  bool res = validParanthesis(s);
  cout << res << endl;
}