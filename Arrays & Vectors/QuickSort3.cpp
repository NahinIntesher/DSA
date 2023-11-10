#include<bits/stdc++.h>
using namespace std;

void printVec(int A[], int N){
    for (int i = 0; i < N; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int partition(int A[], int p, int r){
    int x = A[r];
    int i = p - 1;
    int j;
    for(j = p; j <= r - 1; j++){
        if (A[j] <= x){
            i = i + 1;
        }
        
    }
    swap(A[i], A[j]); 
    swap(A[i+1], A[r]);
    // printVec(A, r);
    // cout << "i : " << i << endl;
    return i+1;
    
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
    n = 8;
    int arr[n] = {18, 23, 56, 26, 89, 37, 28, 48};
    QuickSort(arr, 0, n-1);
    cout<<endl;
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
}