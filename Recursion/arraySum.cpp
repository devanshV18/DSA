#include<iostream>
using namespace std;

int arraySum(int arr[],int size){
    if(size==0) {
        return 0;
    } //base case

    if(size == 1){
        return arr[0];
    } 

    int remArray = arraySum(arr+1,size-1);
    int sum = arr[0] +remArray;
    return sum;
}

int main(){
    int arr1[] = {4,5,6,7,12,4};
    int s = sizeof(arr1)/sizeof(arr1[0]);
    int ans = arraySum(arr1,s);
    cout<<ans<<endl;
}