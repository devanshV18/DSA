#include<iostream>
#include<vector>
using namespace std;


bool isPresent(vector<vector<int>> v, int target){
    if(v.size() == 0){
        return false;
    }
    int row = v.size();
    int col = v[0].size();

    int low = 0;
    int high = row * col - 1;

    while( low <= high ){
        int mid = low + (high - low)/2;
        if(v[mid/col][mid%col] == target){
            return true;
        }
        else if(v[mid/col][mid%col] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> a = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 16;
    bool res = isPresent(a,target);
    cout << res << endl;
}