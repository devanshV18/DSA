#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;


//brute force - 
//Nested loops:-
//traverse the entire array using outer loop and for each element of nums[i] we run a nested loop that runs from nums[i] to end and increase the declare cnt variable inside the outer loop whenever nums[i] == nums[j].
//After each complete traversal (meanining completing counting the occurence/cnt of each nums[i]) we return the cnt if cnt> nums.size()/2 
//if not, we return -1 outside outer loop stating no majority element is present
 
int majorityElementsI(vector<int> &nums){
    for(int i = 0; i<nums.size(); i++){
        int cnt = 0;
        for(int j = 0; j<nums.size(); j++){
            if(nums[i] == nums[j]){
                cnt++;
            }
        }
        if(cnt > (nums.size()/2)){
            return cnt;
        }
    }
    return -1;
}

//Optimised
//Hashing

//traverse thru the array and populate a map with the elements and their frequency
//traverse the map and check for each pair if the freq > n/2 
//if true return the the first (key) of that pair
//if no such key if found return -1

int majorityElement(vector<int> nums){
    unordered_map<int,int> m;
    for(int i = 0; i<nums.size(); i++){
        m[nums[i]]++;
    }

    for(auto it: m){
        if(it.second > (nums.size()/2)){
            return it.first;
        }
    }

    return -1;
}