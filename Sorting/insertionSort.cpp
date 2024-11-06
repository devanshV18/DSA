#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void insertionSort(vector<int> &v){

    int n = v.size();

    for(int i = 1; i<n; i++){
        int key = v[i];
        int j = i - 1;

        while( j >= 0 && v[j] > key ){
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