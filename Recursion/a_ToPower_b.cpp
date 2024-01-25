#include<bits/stdc++.h>
using namespace std;

int power(int a, int b){
    if(b == 1) return a;
    return a * power(a, b - 1);
}

int main(){
    int a, b;
    cout << "\n>> Enter a and b: ";
    cin >> a >> b;
    cout << "\n>> a^b is: " << power(a, b);
}