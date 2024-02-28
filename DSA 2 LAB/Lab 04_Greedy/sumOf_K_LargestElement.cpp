#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    return a > b;
}
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(auto &a: A){
        cin >> a;
    }
    sort(A.begin(), A.end(), comp);
    int sum = 0;
    for (int i = 0; i < K; i++){
        sum += A[i];
    }
    cout << "Sum: " << sum << endl;
    
}