#include<iostream>
using namespace std;
#include<stack>

class Solution {
public:
        bool isValid(string s) {
        int n = s.length();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                } else {
                    char c = st.top();
                    st.pop();
                    if ((s[i] == ')' && c == '(') ||
                        (s[i] == ']' && c == '[') ||
                        (s[i] == '}' && c == '{')) {
                        continue;
                    } else {
                        return false;
                    }
                }
            }
        }
        if (st.empty()) {
            return true;
        }
        return false;
    }
};