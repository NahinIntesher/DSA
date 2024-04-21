#include <bits/stdc++.h>
using namespace std;

void solve(int Case);
int main(){
    int t;
    cin >> t;
    int Case = 1;
    while (t--){
        solve(Case++);
    }
}
void solve(int Case){
    int n, k;
    cin >> n >> k;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 1; i <=n; i++){
        int x;
        cin >> x;
        pq.emplace(x);
    }
    while (k > 2 && pq.size() % (k - 1) != 1){
        pq.emplace(0);
    }
    long long ans = 0;
    while (pq.size() > 1){
        long long sum = 0;
        for (int i = 1; i <= k && !pq.empty(); i++){
            sum += pq.top();
            pq.pop();
        }
        ans += sum;
        pq.emplace(sum);
    }
    cout << "Case " << Case << ": " << ans << endl;
}