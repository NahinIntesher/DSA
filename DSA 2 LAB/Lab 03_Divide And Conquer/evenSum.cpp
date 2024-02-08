#include<iostream>
#include<vector>
using namespace std;

int evenSum(vector<int> A, int start , int end){
    if(start >= end){
        if(A[start] % 2 == 0){
            return A[start];
        }
        else return 0;
    }
    int mid = start + (end - start)/2;
    return evenSum(A, start, mid) + evenSum(A, mid+1, end);
}

int main(){
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Even Number: " << evenSum(A, 0, A.size()-1);
}