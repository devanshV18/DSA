#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int averageWaitTimeSFJ(vector<int> &bt){
    int n = bt.size();

    sort(bt.begin(), bt.end());

    int wt = 0; //0
    int t = bt[0]; //1

    for(int i = 1; i<n; i++){
        wt = wt + t;
        t += bt[i];
    }

    return wt/n;
}

int avgWaitTime(vector<int> j){
    sort(j.begin(), j.end());

    int t = 0, wt = 0;

    for(int i = 0; i<j.size(); i++){
        wt = t + wt;
        t = t + j[i];
    }

    return wt/j.size();
}

int main(){
    vector<int> sjf = {4,3,7,1,2};
    int avg = avgWaitTime(sjf);
    cout << avg << endl;
}