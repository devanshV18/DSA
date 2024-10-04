#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> bubbleSort(vector<int> &v){

    int n = v.size();

    for(int i = n-1; i>=0; i--){
        for(int j = 0; j<= i-1; j++){
            if(v[j] > v[j+1]){
                int temp = v[j+1];
                v[j+1] = v[j];
                v[j] = temp;
            }
        }
    }
    return v;
}

int main(){
    vector<int> test = {13,46,24,52,20,9};
    bubbleSort(test);
    for(int i = 0; i<test.size(); i++){
        cout << test[i] << " ";
    }
}