#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int index, int size, int target){
    if(arr[index] == target)   
        return true;   
    if(index == size - 1) 
        return false;
    
    return linearSearch(arr, index + 1, size, target);
}

int main(){
    int size = 9;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int index = 0;
    int target = 8;

    if(linearSearch(arr, 0, size, target))
        cout << "\n>> " << target << " is found in the array." << endl;
    else
        cout << "\n>> " << target << " is not found in the array." << endl;
}