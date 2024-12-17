#include<iostream>
#include<vector>
using namespace std;


bool lemonade(vector<int> bills){
    int fiveCount = 0;
    int tenCount = 0;
    //count of twenty doesn't make sense as we can't give any change toa nyone using a 20 dollar bill

    for(int i = 0; i<bills.size(); i++){
        //no change to be returned in case of a 5 dollar bill
        if(bills[i] == 5){
            fiveCount++;
            continue; 
        }

        //need to return 5 dollars
        else if(bills[i] == 10){
            if(fiveCount > 0){ //if i have 5 dollar i give and continue
                tenCount++;
                fiveCount--;
                continue;
            }
            else{ //if no 5 dollar bill available return false
                return false;
            }
        }

        //need to retrun 15 dollars
        else {
            if(fiveCount >= 3){
                fiveCount -= 3;
                continue;
            }
            else if(tenCount >= 1 && fiveCount >= 1){
                tenCount--;
                fiveCount--;
                continue;
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
    bool res = lemonade(bills);
    cout << res << endl;
}