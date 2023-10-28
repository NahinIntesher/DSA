#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int count = 0;
    for (int i = start+1; i <= end; i++){
        if(arr[i] <= pivot) count++;
    }
    if(count==0) return start;

    // Place pivet at the right position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Completing partition properly
    int i = start;
    int j = end;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        // i and j are now in such position where the elements of their position should be swaped
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++], arr[j--]); 
        }
    }

    return pivotIndex;
}

void QuickSort(int arr[], int start, int end){
    // Base Case
    if(start>=end){
        return;
    }

    // Partition
    int index = partition(arr, start, end);

    // First part
    QuickSort(arr, start, index-1);
    // Second part
    QuickSort(arr, index+1, end);
}

int main(){
    int n;
    n = 15;
    int arr[n] = {3, 7, 0, 1, 5, 8, 3, 2, 34, 66, 87, 23, 12, 12, 12};
    // cout<<"Enter size of the array/vector (n): ";
    // cin>>n;
    // for(auto &a: arr){
    //     cin>>a;
    // }
    QuickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
}