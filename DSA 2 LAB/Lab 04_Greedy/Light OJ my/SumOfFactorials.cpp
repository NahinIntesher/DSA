#include <bits/stdc++.h>
using namespace std;

void solve(long long int factorials[], int i){
    long long int n;
    cin >> n;
    vector<int> answer;
    for (int i = 20; i >= 0; i--){
        if (factorials[i] <= n){
            n -= factorials[i];
            answer.push_back(i);
        }
    }
    cout << "Case " << i << ": ";
    if (n == 0){
        for (int i = answer.size() - 1; i > 0; i--){
            cout << answer[i] << "!+";
        }
        cout << answer[0] << "!" << endl;
    } else{
        cout << "impossible" << endl;
    }
}
int main(){
    long long int factorials[20] = {}, k = 1;
    factorials[0] = 1;
    for (long long int i = 1; i <= 20; i++){
        factorials[i] = i * factorials[i-1];
    }
    int t =1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(factorials, i);
    }
}
