#include<bits/stdc++.h>
using namespace std;

void printElement(int arr[], int N){
    if(N == 0){
        cout << arr[0] << " ";
        return;
    }
    
    printElement(arr, N - 1);
    cout << arr[N] << " ";
}

int main(){
    int N;
    cout << "\n>> Enter array length: ";
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    printElement(arr, N - 1);
}