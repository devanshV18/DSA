#include<iostream>
using namespace std;

bool isSorted(int arr[] , int size){
    if(size==0 || size==1) return true; // base case - an array with zero or one element is laways sorted1

    if(arr[0]>arr[1]) return false; //array is not sorted

    //to check if array is sorted on first two places but not further we recursively call the function with the argumented array now starting from index 1 i.e. 2nd position to compare 2nd and third elelemnt and so on until base case is reached.

    else{
        bool ans = isSorted(arr+1,size-1);
        return ans;
    }

}


int main(){
    int test[] = {1,2,3,4,5,6,7,4};
    int tsize = sizeof(test)/sizeof(test[0]);  //length calculation

    bool res = isSorted(test,tsize);
    cout<<res<<endl;

}