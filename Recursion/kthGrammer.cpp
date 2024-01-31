#include <iostream>
using namespace std;

int kthGrammar(int n, int k){
    if(n == 1 && k == 1)
        return 0;

    int mid = (1 << n - 1) / 2; /* 1 >> n == pow(2, n) */
    if(k <= mid)
        return kthGrammar(n - 1, k);
    else 
        return !kthGrammar(n - 1, k - mid);
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << kthGrammar(n, k) << endl;
}