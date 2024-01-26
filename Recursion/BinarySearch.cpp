#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int start, int end, int target){
    int mid = (end + start) / 2;
    if(start > end)
        return false;

    if(target == arr[mid])
        return true;
    else if(target < arr[mid])
        binarySearch(arr, start, mid - 1, target);
    else
        binarySearch(arr, mid + 1, end, target);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0;
    int end = 8;
    int target = 8;

    if(binarySearch(arr, start, end, target))
        cout << "\n>> " << target << " is found in the array." << endl;
    else
        cout << "\n>> " << target << " is not found in the array." << endl;
}