#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int> &nums){
    long long sum = 0;

    for(int i = 0; i<nums.size(); i++){
        sum += i;
    }

    for(int i =0; i<nums.size(); i++){
        sum -= nums[i];
    }

    return sum;
}


int main(){

}