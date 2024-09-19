#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> v, int target){
    int s = 0;
    int e = v.size() - 1;
    while(s <= e){
        int mid = s + (e-s) / 2;

        if(v[mid] == target){
        return mid;
        }
        else if(v[mid] < target){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> asc = {2,3,4,10,40};
    int target = 10;
    int res = binarySearch(asc,target);
    cout<<res<<endl;
    
    return 0;
}