#include<bits/stdc++.h>
using namespace std;

int powerLog(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a;

    int x = powerLog(a, b/2);

    if(b % 2 == 0)
        return x * x;
    else
        return a * x * x;
}

int main(){
    int a, b;
    cout << "\n>> Enter a and b: ";
    cin >> a >> b;
    cout << "\n>> a^b is: " << powerLog(a, b);
}