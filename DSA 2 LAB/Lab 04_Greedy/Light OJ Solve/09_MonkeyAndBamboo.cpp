#include <bits/stdc++.h>
using namespace std;

void solve(int i){
    int A[100000] = {0}, diff[100000] = {0};
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
        cin >> A[i];

    diff[0] = A[0];

    int index = 1;
    for (int i = 1; i < m; i++){
        diff[index++] = A[i] - A[i - 1];
    }

    sort(diff, diff + index);
    int x = diff[index - 1] - 1;
        
    bool flag = false;
    for (int i = index - 2; i >= 0; i--){
        if (x == diff[i]){
            x--;
        } else if (x < diff[i]){
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "Case " << i << ": " << diff[index - 1] + 1 << endl;
    else
        cout << "Case " << i << ": " << diff[index - 1] << endl;
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        solve(i);
    }
}
