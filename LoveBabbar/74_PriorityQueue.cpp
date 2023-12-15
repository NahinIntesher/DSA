#include<bits/stdc++.h>
using namespace std;

int main(){

    // Making Max Heap
    priority_queue<int> maxHeap;
    maxHeap.push(4);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(3);
    cout << "\n-> Top of Max Heap: " << maxHeap.top() << endl;

    maxHeap.pop();
    cout << "-> Top of Max Heap: " << maxHeap.top() << endl << endl;


    // Making Min heap
    priority_queue<int, vector<int>, greater<int> > minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);
    cout << "-> Top of min Heap: " << minHeap.top() << endl;
    
    minHeap.pop();
    cout << "-> Top of min Heap: " << minHeap.top() << endl;

}