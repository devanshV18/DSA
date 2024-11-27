#include<iostream>
#include<vector>
using namespace std;

void minCoins(int V){
    vector<int> deno = {1,2,5,10,20,50,100,500,1000};
    
    vector<int> ans;

    for(int i = deno.size() - 1; i>=0 ; i--){
        while( V >= deno[i] ){
            V = V - deno[i];
            ans.push_back(deno[i]);
        }
    }

    cout << ans.size() << endl;

    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " " ;
    }
}

int main(){

    minCoins(123);

    return 0;
}