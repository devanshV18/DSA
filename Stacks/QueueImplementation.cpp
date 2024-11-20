#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int *q;
    int capacity;
    int currSize;
    int start;
    int end;

    Queue(int s){
        capacity = s;
        q = new int[s];
        start = -1;
        end = -1;
        currSize = 0;
    }

    //enqueue or push
    void enqueue(int val){
        if( currSize == capacity ){ 
            cout << "Queue is full" << endl;
            return;
        }
        //empty queue condition
        else if( start == -1 && end == -1){
            start = 0;
            end = 0;
        }
        else{
            end = (end + 1)%capacity;
        }
        q[end] = val;
        currSize = currSize + 1;
    }

    //dequeue/pop

    void dequeue(){
        if(currSize == 0){
            cout << "The queue is empty" << endl;
            return;
        }
        //queue having a single element
        else if( start == end ){ //can also be checked if start == end
            start = -1;
            end = -1;
        }
        else{
            start = (start+1)%capacity;
        }
        currSize--;
    }

    //front
    int front(){
        if(currSize == 0){
            cout << "The queue is empty" << endl;
            return -1;
        }
        return q[start];
    }


    //size
    int size(){
        return currSize;
    }
};


int main(){
    Queue q(5);

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Try enqueueing when the queue is full
    q.enqueue(60); // Should display "Queue is full"

    // Display the front element
    cout << "Front element: " << q.front() << endl;  // Should print 10

    // Display the size of the queue
    cout << "Queue size: " << q.size() << endl;  // Should print 5

    // Dequeue two elements
    q.dequeue();
    q.dequeue();

    // Display the front element after dequeuing
    cout << "Front element after dequeuing 2 elements: " << q.front() << endl;  // Should print 30

    // Display the size of the queue
    cout << "Queue size after dequeuing 2 elements: " << q.size() << endl;  // Should print 3

    // Enqueue more elements to test the circular nature
    q.enqueue(60);
    q.enqueue(70);

    // Display the front element again
    cout << "Front element after enqueueing 60 and 70: " << q.front() << endl;  // Should still print 30

    // Display the size of the queue again
    cout << "Queue size after enqueueing: " << q.size() << endl;  // Should print 5

    // Dequeue all elements
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    // Try dequeuing when the queue is empty
    q.dequeue(); // Should display "Queue is empty"

    return 0;
}