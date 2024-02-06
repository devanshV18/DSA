#include<iostream>
using namespace std;

void printBackwards(int n){
    if (n==0) return ; //base case

    cout<<n<<endl; // processing

    printBackwards(n-1); //recursive relation
    

}


void printForward(int n){
    if(n == 0) return;  //base case

    printForward(n-1); //recursive relation

    cout<<n<<endl; //processing

}



int main(){
    int inp = 6;
    printBackwards(inp);

    printForward(inp);
}