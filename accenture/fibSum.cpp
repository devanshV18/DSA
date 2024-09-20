#include<iostream>
using namespace std;

int fibSum(int n){
    if(n <= 1){
        return n;
    }

    return fibSum(n-1) + fibSum(n-2);
}

int main(){
    int n = 7; 
    int res = fibSum(n); 

    cout << res << endl;
}