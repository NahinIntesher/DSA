#include<bits/stdc++.h>
using namespace std;

void sumation(int n, int sum){
    if(n==0){
        cout << sum;
        return;
    }
    sumation(n - 1, sum + n);
}

int main(){
    int N;
    cin >> N;
    cout << "\n>> Sum of numbers from 1 to n: ";    
    sumation(N, 0);
}