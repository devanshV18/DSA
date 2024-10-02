#include <iostream>
using namespace std;

string RemoveWhitespaces(string str) {
    string result = "";
    
    // Loop through each character of the string
    for (int i = 0; i < str.length(); i++) {
        // If the current character is not a whitespace, add it to the result
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            result += str[i];
        }
    }
    
    return result;  // Return the new string with no whitespaces
}

int main() {
    string inputStr;
    cout << "Enter a string: ";
    getline(cin, inputStr);  // Take a full line of input including spaces
    
    string outputStr = RemoveWhitespaces(inputStr);
    cout << "String without whitespaces: " << outputStr << endl;
    
    return 0;
}
