#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//in insertion sort, we pic each element as an array starting from i = 1, and we make swaps (left wards) in each considered array unti the array is sorted.
// so i moves from first index to the last index and j starts from one plece behind the i'th index in each iteration and j moves backward until j>=0 and v[j] > key //unsorted case, and we swap while movinng left wards,
//once while is false -> 

void insertionSort(vector<int> &v){
    int n = v.size();
    for( int i = 1; i<n; i++){
        int key = v[i];
        int j = i-1;

        while( j>= 0 && v[j] > key){
            v[j+1] = v[j];
            j--;
        }

        v[j+1] = key;
    }
}

int main() {
    vector<int> v = {12, 11, 13, 5, 6};
    insertionSort(v);

    cout << "Sorted array: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}