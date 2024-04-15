#include<iostream>
#include<vector>
using namespace std;

int fib(int N, vector<int>& dp){
    if(N == 0 || N == 1)
        return N;
    if(dp[N] != -1)
        return dp[N];
    dp[N] = fib(N - 1, dp) + fib(N - 2, dp);
    return dp[N];
}

int main(){
    int N;
    cin >> N;
    vector<int> dp(N + 1, -1);  
    cout << fib(N, dp) << endl;
}