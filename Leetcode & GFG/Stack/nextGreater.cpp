#include<iostream>
#include<stack>
using namespace std;
#include<vector>

// int* arr NGEunopt(vector<int> v){
//     int n = v.size();
//     int ans[n];

//     for(int i = 0; i<v.size(); i++){
//         for(int j = i + 1; i<v.size() - 1; j++){
//             if(v[j] > v[i]){
//                 ans[i] = v[j];
//                 break;
//             }
//             else{
//                 ans[i] = -1
//             }
//         }
//     }

//     return ans;

// }

vector<int> nge(vector<int> &nums){
    int n = nums.size();
    vector<int> nge(n);
    stack<int> s;

    for(int i = n-1; i>=0; i--){
        while( !s.empty() && s.top() <= nums[i] ){
            s.pop();
        }
        //after while loop ends either stack gets empty or simply all the smnaller elements have been popped
        if(s.empty()){
            nge[i] = -1;
        }
        else{
            nge[i] = s.top();
        }

        s.push(nums[i]);
    }
    return nge;

}