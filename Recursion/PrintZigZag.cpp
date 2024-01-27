#include<bits/stdc++.h>
using namespace std;

void printZigZag(int N){
    if(N == 0) return;
    cout << N;
    printZigZag(N - 1);
    cout << N;
    printZigZag(N - 1);
    cout << N;
}

int main(){
    int N;
    cout << "Enter n: ";
    cin >> N; 
    printZigZag(N);
}