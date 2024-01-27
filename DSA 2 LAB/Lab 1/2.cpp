//2:
#include<bits/stdc++.h>
using namespace std;

int getSum(int n, int sum){
    if(n == 1)
        return 1;

    sum = n + getSum(n - 1, sum);
    return sum;
}

int main(){
    int n, sum;
    cin >> n;
    int ans = getSum(n, sum);
    cout << ans;
}