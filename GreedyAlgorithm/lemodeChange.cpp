#include<iostream>
#include<vector>
using namespace std;

bool lemondeChange(vector<int> bills){
    int fiveCount = 0, tenCount = 0;

    for( int i = 0; i<bills.size(); i++ ){
        //no change to be returned
        if(bills[i] == 5 ){
            fiveCount++;
        }
        //we need $5 bills to pay the change
        else if( bills[i] == 10 ){
            if( fiveCount > 0 ){
                fiveCount--;
                tenCount++;
            }
            else{
                return false;
            }
        }
        //change can be returned either by a $5 and $10 bill OR 3 $5 bill
        else if(bills[i] == 20){
            if( fiveCount > 0 && tenCount > 0 ){
                fiveCount--;
                tenCount--;
            }
            else if( fiveCount >= 3 ){
                fiveCount -= 3;
            }
            else{
                return false;
            }
        }
    }

    return true;
}

int main(){
    vector<int> bills = {5,5,5,10,20};
    bool res = lemondeChange(bills);
    cout << res << endl;
}