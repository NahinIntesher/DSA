#include <bits/stdc++.h>
using namespace std;
#define SIZE 1005
int n, m, vessel[SIZE];
bool isPossible(int capacity){
    int temp;
    int cnt = 1;
    temp = 0;
    for (int i = 0; i < n; i++){
        if (temp + vessel[i] <= capacity){
            temp = temp + vessel[i];
        }
        else {
            temp = vessel[i];
            cnt++;
        }
    }
    if (cnt > m)
        return false;
    else
        return true;
}
int BS(long long total, int maxCapacity){
    int low, mid, ans;
    long long high;
    low = maxCapacity;
    high = total;
    while (low <= high){
        mid = (low + high) / 2;
        if (isPossible(mid)){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
void solve(int Case){
    cin >> n >> m;
    long long low, total;
    total = low = 0;
    for (int i = 0; i < n; i++){
        cin >> vessel[i];
        total += vessel[i];
        if (vessel[i] > low)
            low = vessel[i];
    }
    int res = BS(total, low);
    cout << "Case " << Case << ": " << res << endl;
}
int main(){
    int t, cn, res;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(i);
    }
}




