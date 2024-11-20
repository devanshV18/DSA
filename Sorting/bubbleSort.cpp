#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//in bubble sort, we do adjacent swapping starting from first and second index, and it goes till last and second last index, inorder to implememt this, we make the i pointer start from right side to mark a point before i, till where j should move and j starts from zero and goes till one index before i (for each i) and make adjacent swaps. After one complete pass of n'th adjacent swap the n'th largest element is at the n'th place from right.
//i.e. after completion of first adjacent apss completely the 1st maximum or simply the maximum element is placed at the 1st place from right i.e. last index.

//NOTE -> for each i -> we complete an entire pass of adjacent swapping.

void bubbleSort(vector<int> &v){
    int n = v.size();

    for( int i = n-1; i>=0; i-- ){
        for(int j = 0; j<=i-1; j++){
            if(v[j] > v[j+1] ){
                swap(v[j], v[j+1]);
            }
        }
    }
}

int main(){
    vector<int> test = {13,46,24,52,20,9};
    bubbleSort(test);
    for(int i = 0; i<test.size(); i++){
        cout << test[i] << " ";
    }
}