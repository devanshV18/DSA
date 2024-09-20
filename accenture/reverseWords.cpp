#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

string reverseWords(string str) {
    stringstream ss(str);
    string word;
    vector<string> words;

    // Extract words from the string
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the order of words
    string reversedStr;
    for (int i = words.size() - 1; i >= 0; i--) {
        reversedStr += words[i];
        if (i > 0) {
            reversedStr += " ";
        }
    }
    return reversedStr;
}

int main() {
    string input = "Hello World";
    string output = reverseWords(input);
    cout << output << endl; // Output: World Hello
    return 0;
}
