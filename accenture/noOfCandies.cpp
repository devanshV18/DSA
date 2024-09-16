#include<vector>
#include<iostream>
using namespace std;

int noOfCandies(int n, int m){
    int c[n];
    cout<<"Please enter price for n Candies"<<endl;
    
    for(int i =0; i<n; i++){
        cin >> c[i];
    }
    int candiesBought = 0;
    for(int i=0; i<n; i++){
        if(c[i]%5==0){
            candiesBought++;
        }
        else if(c[i] <= m && c[i] % 5 != 0){
            m = m - c[i];
            candiesBought++;
        }
        else{
            continue;
        }
    }
    return candiesBought;
}

int main(){
    int ans = noOfCandies(6,7);
    cout<<ans<<endl;
}