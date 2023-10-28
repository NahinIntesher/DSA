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

    void pushFront(int value){
        if(this -> isFull()){ 
            // to check if queue is full
            cout << "Queue is full..." << endl;
            return;
        }
        else if(front == -1){ // first element to push
            front = 0;
            rear = 0;
        }
        else if(front == 0 && rear != size - 1){ // to maintain cyclic nature
            front = size - 1;
        }
        else{ // normal flow
            front--;
        }
        // to push inside the queue
        arr[front] = value;
    }
    
    void pushBack(int value){
        if(this -> isFull()){ 
            // to check if queue is full
            cout << "Queue is full..." << endl;
            return;
        }
        else if(front== -1){ // first element to push
            front = 0;
            rear = 0;
        }
        else if(rear == size - 1 && front != 0){ // to maintain cyclic nature
            rear = 0;
        }
        else{ // normal flow
            rear++;
        }
        // to push inside the queue
        arr[rear] = value;
    }

    void popFront(){
        if(this -> isEmpty()){ // to check if queue is empty
            cout << "Queue is empty..." << endl;
        }
        else if(front == rear){ // single element is present
            front = -1;
            rear = -1;
        }
        else if(front == size - 1){ // to maintain cyclic nature
            front = 0;
        }
        else{ // normal flow
            front++;
        }
    }
    void popBack(){
        if(this -> isEmpty()){ // to check if queue is empty
            cout << "Queue is empty..." << endl;
        }
        else if(front == rear){ // single element is present
            front = -1;
            rear = -1;
        }
        else if(rear == 0){ // to maintain cyclic nature
            rear = size - 1;
        }
        else{ // normal flow
            rear--;
        }
    }

    int getFront(){
        if(this -> isEmpty()){
            return -1;
        }
        return arr[front];
    }

    int getRear(){
        if(this -> isEmpty()){
            return -1;
        }
        return arr[rear];
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

    q.pushFront(13);
    q.pushFront(12);
    q.pushBack(14);


    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    cout << q.isFull() ? 1 : 2;


}