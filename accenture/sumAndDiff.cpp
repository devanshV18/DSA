#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;

int main(){
    int m,n;
    cin >> m;
    cin >> n;

    int evenSum, oddSum = 0;
    int diff;
    for(int i = m; i<=n; i++){
        if( i%2 == 0){
            int sq = sqrt(i);
            evenSum += sq;
        }
        if( i%2 != 0){
            int sq = sqrt(i);
            oddSum += sq;
        }
    }
    diff = evenSum - oddSum;

    cout << diff << endl;
}