#include<iostream>
#include<vector>
using namespace std;

vector<int> minimumCoins(int amount){
    vector<int> denominations = {1,2,5,10,50,100,500,1000};

    vector<int> coins;
    for(int i = denominations.size()-1; i>=0; i--){
        while(amount >= denominations[i]){
            amount -= denominations[i];
            coins.push_back(denominations[i]);
        }   
    }

    cout << coins.size() << endl;
    return coins;
}

int main(){
    int amt = 87;
    vector<int> ans = minimumCoins(amt);

    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}