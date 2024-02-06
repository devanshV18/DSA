#include<iostream>
using namespace std;

  void sayDigits(int n, string arr[]){
    if(n==0) return; //base case


    //processing
    int digit = n%10; //picking out digits from right hand side
    n = n/10; // updating n for next pick 

    //Recursive relation

    sayDigits(n,arr);

    cout<<arr[digit]<<" ";

 }

int main(){

string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int inp = 412;
sayDigits(inp,arr);

}