#include<bits/stdc++.h>
using namespace std;

int getSum(int N){
    if(N == 1){
        return 1;
    }else{
        return N + getSum(N - 1);
    }
}

int main(){
    int N;
    cin >> N;
    int ans = getSum(N);
    cout << "\n>> Sum of numbers from 1 to n: " << ans;
}