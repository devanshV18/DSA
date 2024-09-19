#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool stringArray(vector<string> w1, vector<string> w2){
    string str1 = "";
    string str2 = "";

    for(int i = 0; i<w1.size(); i++){
        str1.append(w1[i]);
    }
    for(int i = 0; i<w2.size(); i++){
        str2.append(w2[i]);
    }

    cout << str1 << endl;
    cout << str2 << endl;

     if(str1 == str2){
        return true;
    }
    else{
        return false;
    }

}


int main(){
    vector<string> w1 = {"ab", "c"};
    vector<string> w2 = {"a", "bc"};
    bool res = stringArray(w1,w2);
    cout << res << endl;
  
}


