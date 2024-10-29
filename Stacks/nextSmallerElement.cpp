#include<iostream>
using namespace std;
#include<stack>
#include<vector>


//brute force
vector<int> nse(vector<int> v){
    int n = v.size();
    vector<int> nse(n,-1);

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(v[j] < v[i]){
                nse[i] = v[j];
                break;
            }
        }
    }
    return nse;
}


//optimised
vector<int> nextSmallerElement(vector<int> v){
    int n = v.size();
    vector<int> nse(n);
    stack<int> s;

    //SINCE WE NEED NEXT smaller element we traverse from right/end
    for(int i = n-1; i>=0; i--){
        //upon reaching each element we check for nse in the stack by running this loop that ensures the stack is popped until it is not empty and the top is >= v[i] as if the top is >= v[i] it can never be the nse for the current element.The popping stops if stack gets empty or top is no more >= v[i]
        while(!s.empty() && s.top() >= v[i]){
            s.pop();
        }

        //if popping stops as stack got empty => no nse present
        if(s.empty()){
            nse[i] = -1;
        }

        //if popping stops because top is no more >=
        else{
            nse[i] = s.top();
        }

        s.push(v[i]);
    }

    return nse;
} 

int main(){
    vector<int> inp = {4, 8, 5, 2, 25};
    vector<int> ans = nextSmallerElement(inp);

    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}