#include<iostream>
#include<vector>
using namespace std;
#include<set>

bool countVowels(string str){
    set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};

    //pick each character
    for(char ch : str){
        //if the character ch is a vowel - a,e,i,o,u,A,E,I,O,U then the count will be 1 else 0 as set has unique occurence
        if(vowels.count(ch)){ //if(1) -> true
            return false;
        }
    }
    //complete traversal without returning false means no vowels is present
    return true;
}

int noOfStringWithoutVowels(vector<string> A){
    int count = 0;
    for(int i = 0; i<A.size(); i++){
        //if string doesn't contain any vowel -> if(true)
        if((countVowels(A[i]))){
            count++;
        }
    }

    return count;
}