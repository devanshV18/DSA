#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
#include<unordered_map>

void replaceWithRank(vector<int> &v){
    int n = v.size();
    vector<int> sortedv = v;
    sort(sortedv.begin(), sortedv.end());

    int rank = 1;
    unordered_map<int, int> m;

    for(int i = 0; i<n; i++){
        if(m.find(sortedv[i]) == m.end()){
            m[sortedv[i]] = rank;
            rank++;
        }
    }

    for(int i = 0; i<n; i++){
        v[i] = m[v[i]];
    }
}

int main(){
    vector<int> a = {1,5,8,15,8,25,9};
    replaceWithRank(a);
    for(int i = 0; i<a.size(); i++){
        cout << a[i] << " ";
    }
}