// 4:
#include<bits/stdc++.h>
using namespace std;

int get_nCr(int n, int r){
    if(n < r)
        return 0;
    if(r == 0)
        return 1;
    if(r == 1)
        return n;
    if(n == 1)
        return 1;
    
    int first = get_nCr(n - 1, r);
    int second = get_nCr(n - 1, r - 1);
    return first + second;
}

int main(){
    int n, r;
    cin >> n >> r;
    int ans = get_nCr(n , r);
    cout << ans;
}