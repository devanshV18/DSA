#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<vector>
#include<unordered_map>

vector<int> sortByFreq(vector<int> v){
    int n = v.size();
    unordered_map<int , int> m;
    for(int i = 0; i<n; i++){
        m[v[i]]++;
    }

    vector<pair<int,int>> pairv;
    for(auto it : m){
        pairv.push_back({it.first,it.second});
    }
    
    sort(pairv.begin(), pairv.end(), [](pair<int, int>& a, pair<int, int>& b) {
    if (a.second != b.second) {
        return a.second > b.second; // Sort by frequency in descending order
    } else {
        return a.first < b.first; // Sort by element in ascending order if frequency is the same
    }
});

    // reverse(pairv.begin(), pairv.end());

    vector<int> res;
    for(auto it : pairv){
        while(it.second != 0){
            res.push_back(it.first);
            it.second--;
        }
    }
    return res;
}

int main(){
    vector<int> a = {1,2,3,2,4,3,1,2};
    vector<int> ans = sortByFreq(a);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}