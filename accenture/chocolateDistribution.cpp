#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long chocolates(vector<long long > A, int m){
     int n = A.size();
     if(n==0 || m == 0){
        return 0;
     }

    sort(A.begin(), A.end());
    if(n<m){
        return -1;
    }

    int mindiff = INT_MAX;
    int currdiff = 0;
    for(int i = 0; i+m-1<n; i++){
        currdiff = A[i+m-1] - A[i];
        mindiff = min(mindiff,currdiff);
    }

    return mindiff;


}

int main(){
    vector<long long> v = {1,3,4,5,2,7,6};
    int s = 5;
    int res = chocolates(v,s);
    cout<<res<<endl;
}