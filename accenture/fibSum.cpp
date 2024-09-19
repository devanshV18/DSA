#include<iostream>
using namespace std;

int fibSum(int n){
    if(n <= 1){
        return n;
    }

    return fibSum(n-1) + fibSum(n-2);
}

int main(){
    int n = 3; 
    int res = fibSum(3); 
    cout << res << endl;
}