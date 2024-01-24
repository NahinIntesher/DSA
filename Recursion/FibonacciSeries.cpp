#include<bits/stdc++.h>
using namespace std;

void getSeries(int N, int a, int b){
    if(N == 1){
        cout << a << " ";
    }
    else if(N == 2){
        cout << a << " " << b << " ";
    }
    else{
        cout << a << " " << b << " ";
        a = a + b;
        b = a + b;
        getSeries(N - 2, a, b);
    }
}

int main(){
    int N;
    cin >> N;
    getSeries(N, 0, 1);
}