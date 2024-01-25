#include<bits/stdc++.h>
using namespace std;

int stair(int N){
    if(N == 1 || N == 2){
        return N;
    }
    int totalways = stair(N - 1) + stair(N - 2);
    return totalways;
}

int main(){
    int N;
    cout << "\n>> Enter 'n' to find n way to climb stairs: ";
    cin >> N;
    cout << "Ways: " << stair(N);
}