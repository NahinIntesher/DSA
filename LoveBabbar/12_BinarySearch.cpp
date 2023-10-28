#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& A, int target){
    int start = 0;
    int end = A.size() - 1;
    int mid;
    while (start <= end){
        mid = start + (end - start)/2;
        if(A[mid] == target){
            return mid;
        }
        else if(A[mid] < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> A = {9, 6, 3, 8, 5, 2, 7, 4, 1};
    cout << binarySearch(A, 6);    
}