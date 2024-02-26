#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        sort(arr, arr+n);
        for(int i = 0; i < n; i++){
            pq.push(arr[i]);
        }
        long long ans = 0;
        while(pq.size() > 1){
            long long top1 = pq.top();
            pq.pop();
            long long top2 = pq.top();
            pq.pop();
            
            long long merged = top1 + top2;
            ans += merged;
            pq.push(merged);
        }
        return ans;
    }
};
int main() {
    long long n;
    cin >> n;
    long long i, a[n];
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution ob;
    cout << ob.minCost(a, n) << endl;
}