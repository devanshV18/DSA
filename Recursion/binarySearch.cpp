#include<iostream>
using namespace std;

bool binarySearch(int arr[],int s, int e, int key){
    if(s>e){
        return false; //base case
    }

    int mid = s+ (e-s)/2;
    if(key==arr[mid]){     //one single case solved
        return true;
    }

    // remaining cases are solved by recursion
    if(key>arr[mid]){
        
        bool remr = binarySearch(arr,mid+1,e,key);
        return remr;
    }

    if(key<arr[mid]){
        bool reml = binarySearch(arr,s,mid-1,key);
        return reml;

    }


}

int main(){
     int arr1[] = {4,5,6,7,12,4};
    int k =6;
    int s = 0;
    int e = sizeof(arr1)/sizeof(arr1[0]) - 1;
    int ans = binarySearch(arr1,s,e,k);
    cout<<ans<<endl;
}