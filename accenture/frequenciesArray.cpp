#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

void freq(vector<int> v){
    unordered_map<int,int> fmap;
    for(int i = 0; i<v.size(); i++){
        fmap[v[i]]++;
    }

    for(auto it : fmap){
        cout << it.first << " - " << it.second << endl;
    }
}

int main(){
    vector<int> inp  = {1,3,5,3,7,1,3,7,5,7};
    freq(inp);
}