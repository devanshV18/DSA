#include<bits/stdc++.h>

using namespace std;
string solve(string str) {
    int n = str.length();
  // bubble sort
  for (int i = 0; i < n ; i++) {
    for (int j = 0; j < n - 1; j++) {

      if (str[j] > str[j + 1]) {
        char temp = str[j];
        str[j] = str[j + 1];
        str[j + 1] = temp;
      }
    }
  }

  return str;
}
int main() {
  string str = "zxcbg";
//   int n = str.length();

  cout << "Given string: " << "\n";
  cout << str << "\n";

  cout << "After sorting: " << "\n";
  cout << solve(str) << "\n";
  return 0;
}