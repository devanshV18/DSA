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

//OPTIMAL - BY ELIMINATING RIGHT ARRAY
#include <vector>
#include <iostream>
using namespace std;

// Optimized solution for the Candy Problem with O(N) space
int minCandiesOptimal(vector<int> &childrenRatings) {
    int n = childrenRatings.size();
    if (n == 0) return 0;

    // Initialize candies array
    vector<int> candies(n, 1);  // Everyone gets at least one candy

    // Left-to-right pass
    for (int i = 1; i < n; i++) {
        if (childrenRatings[i] > childrenRatings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right-to-left pass combined with calculating the result
    int minCandies = candies[n - 1];  // Start with the last child's candies
    for (int j = n - 2; j >= 0; j--) {
        if (childrenRatings[j] > childrenRatings[j + 1]) {
            candies[j] = max(candies[j], candies[j + 1] + 1);
        }
        minCandies += candies[j];
    }

    return minCandies;
}


int main(){
    vector<int> ratings = {1, 3, 2, 2, 1};
    int minimumCandies = minCandiesOptimal(ratings);
    cout << minimumCandies << endl;
}