// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<vector>

int main() {
    
    vector<int> nums = {1,2,3,4,5};
   
    
    for(int i = 0; i<nums.size()/2; i++){
        int temp = nums[i];
        nums[i] = nums[nums.size() - i - 1];
        nums[nums.size() - i - 1] = temp;
    }
    
    for(int i = 0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    

    return 0;
}