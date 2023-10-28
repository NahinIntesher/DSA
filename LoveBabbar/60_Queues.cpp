#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int *arr;
    int front;
    int rear;
    int size;
    Queue(int size){
        this -> size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enQueue(int value){
        if(this -> isFull()){ 
            // to check if queue is full
            cout << "Queue is full..." << endl;
            return;
        }
        else if(front== -1){ // first element to push
            front = 0;
            rear = 0;
        }
        else if(rear == size - 1){ // to maintain cyclic nature
            rear = 0;
        }
        else{ // normal flow
            rear++;
        }
        // to push inside the queue
        arr[rear] = value;
    }

    void deQueue(){
        if(this -> isEmpty()){ // to check if queue is empty
            cout << "Queue is empty..." << endl;
            return;
        }
        else if(front == rear){ // single element is present
            front = -1;
            rear = -1;
            return;
        }
        else if(front == size - 1){ // to maintain cyclic nature
            front = 0;
        }
        else{ // normal flow
            front++;
        }
    }

    int Front(){
        if(front == rear){
            return -1;
        }
        return arr[front];
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        return false;
    }

    bool isFull() {
        if(front == (rear + 1) % size){
            return true;
        }
        return false;
    }

};


int main(){
    Queue q(3);
    q.enQueue(5);
    q.deQueue();

    if(q.isEmpty()){
        cout << "Queue is empty..." << endl;
    }
    else{
        cout << "Queue is not empty..." << endl;
    }

    if(q.isFull()){
        cout << "Queue is full..." << endl;
    }
    else{
        cout << "Queue is not full..." << endl;
    }
}