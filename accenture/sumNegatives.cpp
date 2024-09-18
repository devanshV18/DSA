#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {-3,2,4,-1};
    int sum = 0;
    for(int i = 0; i<v.size(); i++ ){
        if(v[i] < 0){
            sum += v[i];
        }
    }
    cout << sum << endl;
}