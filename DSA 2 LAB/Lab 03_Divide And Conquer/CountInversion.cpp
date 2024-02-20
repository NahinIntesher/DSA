#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>& A, int start, int end, int mid){
    int inversion = 0;
    int len1 = mid - start + 1;
    int len2 = end - mid;
    vector<int> first(len1);
    vector<int> second(len2);

    int mainArrayIndex = start;
    for(int i = 0; i < len1; i++)
        first[i] = A[mainArrayIndex++];
    mainArrayIndex = mid+1;
    for(int i = 0; i < len1; i++)
        second[i] = A[mainArrayIndex++];

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;
    while(index1 < len1 && index2 < len2){
        if(first[index1] <= second[index2]){
            A[mainArrayIndex++] = first[index1++];
        } 
        else{
            A[mainArrayIndex++] = second[index2++];
            inversion += len1 - index1;// elements after this, including this element
        }
    }
    while(index1 < len1)
        A[mainArrayIndex++] = first[index1++];
    while(index2 < len2)
        A[mainArrayIndex++] = second[index2++];
    return inversion;
}
int countInversion(vector<int> &A, int low, int high){
    int inversion = 0;
    if(low == high)
        return 0;
    int mid = low + (high - low) / 2;
    inversion += countInversion(A, low, mid);
    inversion += countInversion(A, mid+1, high);
    inversion += merge(A, low, high, mid);
    return inversion;
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &a: A)
        cin >> a;
    cout << "#inversions: " << countInversion(A, 0, A.size()-1); 
}
// int countInversion(vector<int> &A, int low, int high){
//     int inversion = 0;
//     for (int i = 0; i < A.size(); i++){
//         for (int j = i; j < A.size(); j++){
//             if(A[i] > A[j])
//                 inversion++;
//         }
//     }
//     return inversion;    
// }