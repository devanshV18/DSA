#include<iostream>
#include<algorithm>
#include<cctype> // for isalnum function
using namespace std;


//Brute force and string building method -> takes extra space and memory
bool validPalindrome(string s){
    string newStr = "";

    //picking each character from the string and checking if it is alphanumeric, if it is , we add it to newStr after converting it to lower case.

    for( char i : s ){
        if(isalnum(i)){
            newStr += tolower(i);
        }
    }

    //do this check or simply reverse the string and compare s and newStr, if they are same return true else return false
    int n = newStr.length();
    for(int i = 0; i<n/2; i++ ){
        if( newStr[i] != newStr[n-i-1] ){
            return false;
        }
    }

    return true;
}


//OPTIMAL -> initially we place two pointers, one at start and one at end. If both are non alnum, move pointers inward until both both point to a alnum char. once both point to a alnum we convert both in lower case and compare, if they are not same , return false right away, if they are same, simply mover pointers inward to continue iteration.

// the while loop runs until l is smaller than r , i.e. at any point if l==r. l>r loop ends. If loop ends successfully, then it means that we didn't encounter any false case, hence entire string is traversed and we return true.

bool isValidPalindrome(string s){
    int l = 0;
    int r = s.length() - 1;

    while ( l < r ){
        while( l < r && !isalnum(s[l])) l++;

        while( l < r && !isalnum(s[r])) r--;

        if( tolower(s[l]) != tolower(s[r]) ) {
            return false;
        }

        l++;
        r--;
    }
    
    return true;
}



int main(){
    string test = "A man, a plan, a canal: Panama";
    bool res = isValidPalindrome(test);
    cout << res << endl;
}
