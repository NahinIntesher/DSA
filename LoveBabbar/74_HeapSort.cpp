#include<bits/stdc++.h>
using namespace std;



/* Max Heapify with 0 indexing array */
void heapify(int arr[], int size, int index){
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;
    
    // Swaping with max child
    if(left < size && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < size && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != index){
        swap(arr[index] , arr[largest]);
        heapify(arr, size, largest);
    }
}

/* Time Complexity O(logN) */
void heapSort(int arr[], int n){
    
    // Building Heap
    for(int i = n/2; i >= 1; i--){
        heapify(arr, n, i);
    }

    // Sorting
    int size = n;
    while(size > 1){
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
    
}

int main(){
    int n = 15;
    int arr[n-1] = {-1, 150, 80, 10, 220, 25, 370, 450, 60, 20, 55, 45, 50, 30, 70, 1};

    heapSort(arr, n);
    
    cout << "-> Elements After sorting:" << endl;
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }

}