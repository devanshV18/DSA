#include<iostream>
using namespace std;

int printFib(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    int term = printFib(n-1) + printFib(n-2);
    return term;

}

int main(){
    int inp =5;
    int res = printFib(inp);
    cout<<res<<endl;
}