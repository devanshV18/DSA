#include<iostream>
using namespace std;

int fac(int n){
    if(n==0) return 1;  //base case

    int small = fac(n-1);
    int big = n * small;
    return big;
}



int main(){
    int inp;
    cout << "Type a number: "<<endl;
    cin >> inp;
    int result;
    result = fac(inp);
    cout<<result<<endl;
}