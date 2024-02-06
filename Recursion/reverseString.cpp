#include<iostream>
using namespace std;

void reverse(string& str, int i , int j){  //pass by reference
    //base case

    if(i>j){
        return;
    }


    //ek case solved
    swap(str[i],str[j]);
    i++;
    j--;

    //recursion
    reverse(str,i,j);
}



int main(){
    string name = "devansh";
    reverse(name, 0, name.length()-1);
    cout<<name<<endl;
}