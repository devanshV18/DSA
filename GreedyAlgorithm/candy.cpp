#include<vector>
#include<iostream>
using namespace std;


//BRUTE FORCE
int minCandies( vector<int> &childrenRatings){
    int n = childrenRatings.size();
    vector<int> candiesWrtLeft(n,1);
    vector<int> candiesWrtRight(n,1);
    
    for(int i = 1; i<n; i++){
        if(childrenRatings[i] > childrenRatings[i-1]){
             candiesWrtLeft[i] = candiesWrtLeft[i - 1] + candiesWrtLeft[i];
        }
    }    
    

    for(int j = n-2; j>=0; j--){
        if(childrenRatings[j]>childrenRatings[j+1]){
            candiesWrtRight[j] = candiesWrtRight[j + 1] + candiesWrtRight[j];
        }
    }

    
    int minCandies = 0;
    for(int i = 0; i<n; i++){
        minCandies += max(candiesWrtLeft[i], candiesWrtRight[i]);
    }

    return minCandies;
}

int main(){
    vector<int> ratings = {0,2,4,3,2,1,1,3,5,6,4,0,0};
    int minimumCandies = minCandies(ratings);
    cout << minimumCandies << endl;
}