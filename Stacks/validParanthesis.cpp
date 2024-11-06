#include<iostream>
using namespace std;
#include<stack>


bool balancedUnbalanced(string s){
  stack<char> st;

  for( int i = 0; i<s.length(); i++ ){

    //opening brackets are simply preserved in the stack
    if( s[i] == '(' || s[i] == '{' || s[i] == '['){
      st.push(s[i]);
    }

    else{ // else starts handling case of closing bracket.

      //case wher closing bracket is encountered but stack itself has got empty -> which means there is an umatched / unbalanced brackert
      if( st.empty() ){
        return false
      }

      //the stack is not empty and we have a closing bracket so lets check the combination

      //getting the top of stack (an oepning bracket to match combinations)
      char top = st.top();

      //combination matches
      if( ( exp[i] == ')' && c == '(' ) || ( exp[i] == '}' && c == '{' ) || ( exp[i] == ']' && c == '[' ) ){
         st.pop();
      }

      //combiantion doesn't match
      else{
        return false;
      }

    }

    if(st.empty()){
      return true;
    }
    else{
      return false;
    }


  }
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