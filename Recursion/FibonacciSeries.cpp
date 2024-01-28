#include<bits/stdc++.h>
using namespace std;

// Get N'th number
int fib(int N){
    if(N == 1){
        return 0;
    }
    if(N == 2){
        return 1;
    }
    return fib(N - 2) + fib(N - 1);
}

// Get Series
void getFibonacciSeries(int N, int a, int b){
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
        getFibonacciSeries(N - 2, a, b);
    }
}

int main(){
    int N;
    cout << "Enter n: ";
    cin >> N;
    cout << "\n>> N'th fibonacci number is: " << fib(N) << endl;
    cout << "\n>> Fibonacci series is: ";
    getFibonacciSeries(N, 0, 1);
}