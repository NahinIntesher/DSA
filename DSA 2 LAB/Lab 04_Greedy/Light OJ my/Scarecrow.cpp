#include <bits/stdc++.h>
using namespace std;
void solve(int Case) {
    int N; 
    cin >> N;
    string S;
    cin >> S;
    int scarecrows = 0;
    for (int i = 0; i < N; i++){
        if(S[i] == '.'){
           scarecrows++;
           i += 2;
        }
    }  
    cout << "Case " << Case << ": " << scarecrows << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(i);    
    }
}
