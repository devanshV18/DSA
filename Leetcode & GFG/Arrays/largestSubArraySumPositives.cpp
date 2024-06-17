/*
    Let's go through the example arr = {10, 5, 2, 7, 1, 9} and K = 15.

Initialization:

sum_map is empty.
cumulative_sum = 0.
max_length = 0.
Iteration Steps:

i = 0:

cumulative_sum = 0 + 10 = 10
10 != 15, so max_length remains 0.
sum_map is updated: {10: 0}.
i = 1:

cumulative_sum = 10 + 5 = 15
15 == 15, so max_length = 2 (sub-array: {10, 5}).
sum_map is updated: {10: 0, 15: 1}.
i = 2:

cumulative_sum = 15 + 2 = 17
17 - 15 = 2, not in sum_map, so max_length remains 2.
sum_map is updated: {10: 0, 15: 1, 17: 2}.
i = 3:

cumulative_sum = 17 + 7 = 24
24 - 15 = 9, not in sum_map, so max_length remains 2.
sum_map is updated: {10: 0, 15: 1, 17: 2, 24: 3}.
i = 4:

cumulative_sum = 24 + 1 = 25
25 - 15 = 10, found in sum_map with index 0.
max_length = max(2, 4 - 0) = 4 (sub-array: {5, 2, 7, 1}).
sum_map is updated: {10: 0, 15: 1, 17: 2, 24: 3, 25: 4}.
i = 5:

cumulative_sum = 25 + 9 = 34
34 - 15 = 19, not in sum_map, so max_length remains 4.
sum_map is updated: {10: 0, 15: 1, 17: 2, 24: 3, 25: 4, 34: 5}.
Result:

After the loop, max_length is 4.
The longest sub-array with sum 15 is {5, 2, 7, 1} with length 4.
*/



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

        if(sum_map.find(cumulative_sum - K) != sum_map.end()){  //if sum_map contains cumulative_sum - K ->checks in key of unordered_map
            max_length = max(max_length, i - sum_map[cumulative_sum - K]);
        }   

        if(sum_map.find(cumulative_sum) == sum_map.end()){  //if cumulative_sum key is not yeat present in map
            sum_map[cumulative_sum] = i;
        }

        return max_length;

    }
}

    

int main(){

}