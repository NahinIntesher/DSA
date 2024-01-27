// 1:
#include<bits/stdc++.h>
using namespace std;


int getPower(int x, int y){
    if(y == 1){
        return x;
    }
    x = x * getPower(x, y - 1);
    return x;
}

int main(){
    int x, y;
    cin >> x >> y;
    int ans = getPower(x, y);
    cout << ans;
}










