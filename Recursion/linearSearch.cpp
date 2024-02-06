#include<iostream>
using namespace std;
bool linearSearch(int arr[] , int size , int k){
    //base casse
    if(size==0) return false; //if size runs out and eleement not found

    if(arr[0] == k){
        return true;  //solving a single case
    }

    else{
        bool rem = linearSearch(arr+1,size-1,k);
        return rem;
    }
    
}
int main(){
    int arr1[] = {4,5,6,7,12,4};
    int k =100;
    int s = sizeof(arr1)/sizeof(arr1[0]);
    bool ans = linearSearch(arr1,s,k);
    cout<<ans<<endl;
}