#include<vector>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxCookies(vector<int> g, vector<int> s){
    int n = g.size();
    int m = s.size();

    int l,r = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    while(l < m){
        if(g[r] <= s[l]){
            l++;
            r++;
        }
        else{
            l++;
        }
    }

    return r;
}

int main(){
    vector<int> size = {1,1,2,2,3,4};
    vector<int> greed = {1,1,2,2,3};

    int ans = maxCookies(greed,size);
    cout<<ans<<endl;

}