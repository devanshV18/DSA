#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

bool isPrime(int n){
    if(n<1){
        return false;
    }

    int sq = sqrt(n);
    for(int i = 2; i<sq; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n = 17;
    bool res = isPrime(n);
    cout << res << endl;
}