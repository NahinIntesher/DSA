#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int> &arr, int start, int end){
    int mid = (start+end)/2;

    int len1 = mid - start + 1;
    int len2 = end - mid;
    
    // Creating 2 array dynamically. But if we want, we create normally
    int *first = new int[len1];
    int *second = new int[len2];

    // copying values
    int mainArrayIndex = start;
    for (int i = 0; i < len1; i++){
        // Assining value and incrementing index together
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++){
        // Assining value and incrementing index together
        second[i] = arr[mainArrayIndex++]; 
    }

    // Merging 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;
    while(index1<len1 && index2<len2){
        if(first[index1] < second[index2]){
            // Assining value and incrementing index together
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            // Assining value and incrementing index together
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // For the rest elements of first array if something left
    while (index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }

    // For the rest elements of first array if something left
    while (index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }
    
    /* If we allocate first & second array dynamically, 
        it is good practice to delete them after using*/
        delete []first;
        delete []second;
}



void MergeSort(vector<int> &arr, int start, int end){
    // Base case
    if(start >= end){
        return;
    }
    int mid = (start+end)/2;
    // First part
    MergeSort(arr, start, mid);
    // Second part
    MergeSort(arr, mid+1, end);
    // Merging
    Merge(arr, start, end);
}



int main(){
    int n;
    n = 15;
    vector<int> arr = {3, 7, 0, 1, 5, 8, 3, 2, 34, 66, 87, 23, 12, 12, 12};
    // cout<<"Enter size of the array/vector (n): ";
    // cin>>n;
    // for(auto &a: arr){
    //     cin>>a;
    // }
    MergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
}