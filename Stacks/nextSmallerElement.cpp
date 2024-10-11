#include<iostream>
using namespace std;
#include<stack>
#include<vector>


//brute force
vector<int> nse(vector<int> v){
    int n = v.size();
    vector<int> nge(n,-1);

    for( int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            if(v[j] < v[i]){
                nge[i] = v[j];
                break;
            }
        }
    }

    return nge;
}


//optimised
vector<int> nextSmallerElement(vector<int> v){
    int n = v.size();
    vector<int> nse(n);
    stack<int> s;

    for(int i = n-1; i>=0; i--){
        while( !s.empty() && s.top() >= v[i] ){
            s.pop();
        }

        if(s.empty()){
            nse[i] = -1;
        }
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