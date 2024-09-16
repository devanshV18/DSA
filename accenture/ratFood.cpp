#include<vector>
#include<iostream>
using namespace std;

int houses(vector<int> h, int r, int unit){
    int n = h.size();
    if(n == 0){
        return -1;
    }
    int foodreq = r * unit;
    int foodgathered = 0;
    for(int i =0; i<n; i++){
        foodgathered += h[i];
        if(foodgathered >= foodreq){
            return i+1;
        }
    }
    return 0;
}

int main(){
    vector<int> check = {2,8,3,5,7,4,1,2};
    int r = 7;
    int unit = 2;
    int ans = houses(check, r, unit);
    cout << ans << endl;
}