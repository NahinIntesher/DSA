#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end){
    int pivot = arr[start];
    
    // Completing partition properly
    int i = start;
    int j = end;
    while(i<=j){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        // Pivot should be swaped now
        if(i>j){
            swap(arr[start], arr[j]);
            return j;
        }
        // if 'i' is not greater than 'j' then two elements should be swaped
        swap(arr[i++],arr[j--]);
    }
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