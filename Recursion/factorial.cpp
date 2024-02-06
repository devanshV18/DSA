#include<iostream>
using namespace std;

int fac(int n){
    if(n==0) return 1;  //base case

    int smallprob = fac(n-1);
    int bigprob = n * smallprob;
    return bigprob;
}



int main(){
    int inp;
    cout << "Type a number: "<<endl;
    cin >> inp;
    int result;
    result = fac(inp);
    cout<<result<<endl;
}