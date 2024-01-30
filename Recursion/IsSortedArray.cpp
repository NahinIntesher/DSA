#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int index, int size){
    if(index == size - 1)
        return true;
    if(arr[index] > arr[index + 1])
        return false;
    
    return isSorted(arr, index + 1, size);
}

int main(){
    int N;
    cout << "\n>> Enter array size: ";
    cin >> N;
    int arr[N];
    cout << ">> Enter array elements: ";
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    if(isSorted(arr, 0, N))
        cout << "\n>> The array is sorted.";
    else 
        cout << "\n>> The array is not sorted.";
}