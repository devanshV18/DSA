#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int largestSubArraySum(vector<int> &nums, int K){
    unordered_map<int,int> sum_map;
    int cumulative_sum = 0;
    int max_length = 0;

    for(int i =0; i<nums.size(); i++){
        cumulative_sum += nums[i];

        if(cumulative_sum == K){
            max_length = i+1;
        }

        if(sum_map.find(cumulative_sum - K) != sum_map.end()){
            max_length = max(max_length, i - sum_map[cumulative_sum - K]);
        }   

        if(sum_map.find(cumulative_sum) == sum_map.end()){
            sum_map[cumulative_sum] = i;
        }

        return max_length;

    }
}

    

int main(){

}