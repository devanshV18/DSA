#include<iostream>
#include<vector>
using namespace std;

void minCoins(int V){
    vector<int> deno = {1,2,5,10,20,50,100,500,1000};
    
    vector<int> ans;

    for(int i = deno.size() - 1; i>=0; i--){
        while(V >= deno[i]){
            V -= deno[i];
            ans.push_back(deno[i]);
        }
    }

    cout << ans.size() << endl;

    cout << "Coins used: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){

    minCoins(49);

    return 0;
}