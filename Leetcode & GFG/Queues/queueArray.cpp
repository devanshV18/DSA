#include<iostream>
using namespace std;

class Queue{
    int capacity;
    int *q;
    int cs;
    int s;
    int e;

    Queue(int size){
        capacity = size;
        q = new int[size];
        cs = 0;
        s = e = -1; 
    }

    void push(int val){
        //Full queue
        if( cs == capacity){
            cout << "Queue if FULL";
        }

        //empty queue
        if(cs == 0){
            s = 0;
            e = 0;
        }
        //edge case and Normal trivial case handled together
        else{
            e = (e+1) % capacity;
        }
        q[e] = val;
        cs++;
    }

    int pop(){
        //Empty case
        if(cs == 0){
            cout<< "Queue is Empty" <<endl;
        }

        int popel = q[s];

        //Queue destruction case
        if(cs == 1){
            s=e=-1;
        }

        //remaining trivial case
        else{
            s = (s+1) % capacity;
        }

        cs -= 1;
        return popel;
    }

    int top(){
        if(cs == 0){
            cout<<"Queue is Empty"<<endl;
        }
        return q[s];
    }

    int size(){
        return cs;
    }
};