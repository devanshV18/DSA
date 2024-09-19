#include<iostream>
using namespace std;

int reversednumber(int num){
    int rev = 0;
    while(num != 0){
        int dig = num % 10;
        rev = rev * 10 + dig;
        num = num/10;
    }
    return rev;
}

int main(){
    int res = reversednumber(987654);
    cout << res << endl;
}