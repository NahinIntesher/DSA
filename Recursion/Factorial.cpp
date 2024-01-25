#include<bits/stdc++.h>
using namespace std;

int fact(int N){
    if(N == 1) return 1;
    return N * fact(N - 1);
}

int main(){
    int N;
    cout << "\n>> Enter n: ";
    cin >> N;
    cout << "\n>> " << N << "! is: " << fact(N);
}
