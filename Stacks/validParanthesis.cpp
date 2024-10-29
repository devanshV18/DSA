#include<iostream>
using namespace std;
#include<stack>


bool balancedUnbalanced(string s){
  stack<char> st;

  for(int i = 0; i<s.length(); i++){

    //if i encounter a opening bracket
    if( s[i] == '(' || s[i] == '{' || s[i] == '['){
      st.push(s[i]);
    }

    //handling entire case for closing bracket inside this else
    else{
        //closing bracket is encountered as we are inside else but stack got empty = clearly unbalanced
        if( st.empty() ){
          return false;
        }

        //we have encountered a closing bracket and the stack is also not empty.
        // noe we need to compare current closing bracket with latest opening bracket.

        char ch = st.top();

        //if the brackets are of same type that is the brackets match then we pop and move
        if( (s[i] == ')' && ch == '(') || (s[i] == '}' && ch == '{') || (s[i] == ']' && ch == '[')){
          st.pop();
        }
        else{
          //if a unmatch case is found -> return false as it will leave an umatched opening bracket at the end.
          return false;
        }
    }
  }

  //after loop ends we just make an additional check that the stack is empty after checking all combinations
  return st.empty();
}


// bool validParanthesis(string exp){
//     stack<char> st;

//     for(int i = 0; i<exp.length(); i++){

//       //opening brackets
//       if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
//         st.push(exp[i]);
//       }

//       //closing brackets
//       else{ 
        
//         //closing bracket encountered but stack got empty
//         if(st.empty()){
//           return false;
//         }

//         //closing bracket but stack is not empty
//         char c = st.top();
        
//         //if combination matched -> pop and move futher in the iteration
//         if( ( exp[i] == ')' && c == '(' ) || ( exp[i] == '}' && c == '{' ) || ( exp[i] == ']' && c == '[' ) ){
//           st.pop();
//         }

//         //if a mismatch occurs -> return false
//         else{
//           return false;
//         }
      
//       }
//     }

//     //after the complete string is iterated

//     //check if stack is empty
//     if(st.empty()){
//       return true;
//     }

//     else{
//       return false;
//     }
// }

int main(){
  string s;
  cin >> s;
  bool res = balancedUnbalanced(s);
  cout << res << endl;
}