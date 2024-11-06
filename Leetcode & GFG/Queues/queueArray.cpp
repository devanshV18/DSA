#include<iostream>
using namespace std;

class Queue{

public:
    int capacity;
    int* q;
    int cs;
    int s
    int e;
    
    Queue(int size){
        capacity = size;
        q = new int[size];
        cs = 0;
        s=e=-1;
    }

    void enqueue(int x){
        if( cs == capacity ){
            cout << "Queue if Full";
        }

        //if not full we can enque
        //case 1 -> empty queue -> both s and e  should move.
        if( cs == 0 ){
            s = 0;
            e = 0;
        }
        else{
            e = (e+1) % capacity;
        }
        q[e] = x;
        cs++;
    }

    void dequeue(){
        if( cs == 0 ){
            cout << "Queue is Empty" << endl;
        }

        //queue destruction case
        if( cs == 1 ){
            s=e=-1;
        }
        else{
            s = (s+1) % capacity;
        }
        cs--;
    }

    int front(){
        if( cs == 0 ){
            cout << "Queue is Empty" << endl;
        }

        return q[s];
    }

    int size(){
        return cs;
    }
}

//cases to handle:- 
//1. Pushing into an empty queue -> when queue is empty both s and e moves to 0 from -1 and then push occurs and cs++ else only e moves as per modulus operator.
//2. while popping(deque) if cs==0 || s==e it means the element you are dequeing is the last and this dequeu destroys the queue, thus to handle this, s=e=-1, if its not the last elemet simply increment s by the modulus operator.