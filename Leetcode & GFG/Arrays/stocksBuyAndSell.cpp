#include<vector>
#include<iostream>
using namespace std;

int maxProfit(vector<int> prices){
    int l = 0;
    int r = 1;

    int maxP = 0;
    int profit;

    while(r<prices.size()){
        if(prices[l] >= prices[r]){
            l = r;
        }

        else{
            profit = prices[r] - prices[l];
            maxP = max(maxP, profit);
        }

        r++; //universal incerement - occurs in both case
    }

    return maxP;

}