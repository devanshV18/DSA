#include<iostream>
#include<stack>
using namespace std;
#include<vector>

//circular array approach
// TC -> O(N^2)
// SC -> O(N)

vector<int> nseII(vector<int> &nums){
    int n = nums.size();
    vector<int> nge(n,-1);
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<=i+n-1; j++){
            int index = j%n;

            if(nums[index] > nums[i]){
                nge[i] = nums[index];
                break;
            }
        }
    }
    return nge;
}


//optimised approach -> monotonic stack

vector<int> nseIIOptimised(vector<int> &nums){
    int n = nums.size();
    vector<int> nge(n,-1);
    stack<int> st;

    for(int i = 2*n-1; i>=0; i--){
        while(!st.empty() && st.top() <= nums[i%n]){
            st.pop();
        }

        if( i < n ){
            nge[i] = st.empty() ? -1 : st.top();
        }

        st.push(nums[i%n]);
    }

    return nge;
} 
