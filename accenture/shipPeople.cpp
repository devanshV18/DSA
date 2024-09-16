#include<iostream>
using namespace std;

int main(){
    cout<< "Please Enter Capacity of the Vsssel Ship" << endl;

    int capacity;
    cin >> capacity;

    cout<< "Please Enter number of people" << endl;

    int people;
    cin >> people;

    if(people>capacity){
        if(people % capacity > 0){
            cout << "Number of rounds to be made is: " << (people / capacity)+1 << endl;
        }
        if(people % capacity == 0){
            cout << "Number of rounds to be made is: " << people / capacity << endl; 
        }
    }
    else{
        cout << "Number of rounds to be made is: " << 1 << endl;
    }
    

}