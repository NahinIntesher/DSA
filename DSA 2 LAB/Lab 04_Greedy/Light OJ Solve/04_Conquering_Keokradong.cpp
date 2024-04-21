#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 3;
int dist[MAXN];
int n, k;
bool isPossible(int d){
    int dayRemain = k + 1;
    int distReamin = n + 1;
    int camp = 0;
    while(camp <= n) {
        int go = 0;
        while(camp <= n && go + dist[camp] <= d) {
            if(dayRemain == distReamin) return true;
            go += dist[camp++];
            distReamin--;
        }
        dayRemain--;
    }
    return (dayRemain == distReamin);
}
int binSearch(int s, int t){
    int ret;
    while(s <= t) {
        int mid = (s + t) >> 1;
        if(isPossible(mid)) {
            ret = mid;
            t = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ret;
}
void print_ans(int d){
    int dayRemain = k + 1;
    int distReamin = n + 1;
    int camp = 0;
    while(camp <= n) {
        int go = 0;
        while(camp <= n && go + dist[camp] <= d) {
            if(dayRemain == distReamin) {
                cout << go + dist[camp++] << endl;

                while(camp <= n)
                    cout << dist[camp++] << endl;
                return;
            }
            go += dist[camp++];
            distReamin--;
        }
        cout << go << endl;
        dayRemain--;
    }
}
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n >> k;
        int mx = -1, sum = 0;
        for(int i = 0; i <= n; ++i) {
            cin >> dist[i];
            sum += dist[i];
            if(dist[i] > mx) mx = dist[i];
        }
        int cost = binSearch(mx, sum);
        cout << "Case " << i << ": " << cost << endl;
        print_ans(cost);
    }
}