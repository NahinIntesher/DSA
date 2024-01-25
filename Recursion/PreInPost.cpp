#include<bits/stdc++.h>
using namespace std;

void PreInPost(int N){
    if(N == 0) return;
    cout << "Pre: " << N << endl;
    PreInPost(N - 1);
    cout << "In: " << N << endl;
    PreInPost(N - 1);
    cout << "Post: " << N << endl;
}

int main(){
    int N;
    cout << "Enter n: ";
    cin >> N; 
    PreInPost(N);
}