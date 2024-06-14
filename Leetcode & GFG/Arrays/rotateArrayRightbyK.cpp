/*
    ALGORITHM 

    1. Understand the rotation.
        k rotation to the right means each element of array will shift to the right k times.

        NOTE - if k is larger than size n of the array the then rotating the array k times is eqv to rotating the array k%n times.

    2. Normalise k - calculate k = k%n to bring k within the limits of the rotation.

    3. reverse the entire array

    **4. reverse first k elements 
    **5. reverse the remainin n-k elements.
*/



#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


void rotateByKRight(vector<int> &nums, int k){
    int n = nums.size();
    k = k % n;

    reverse(nums.begin(),nums.end()); //reverse entire array after normalisation
    reverse(nums.begin(),nums.begin()+k); //reverse first k
    reverse(nums.begin()+k,nums.end()); // reverse n-k elements

}




using namespace std;

int main(){
    
}