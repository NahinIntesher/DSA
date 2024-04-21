#include<bits/stdc++.h>
using namespace std;

int root[10003], mafia[10003];
vector<int> g[10003];

int dfs(int u, int p) {
    int re=0;

    for(int v: g[u]) {
        re += dfs(v,u);
    }

    re += abs(mafia[u] - 1);
    mafia[p] += mafia[u] - 1;

    return re;
}

int main() {
    int T, n;
    cin >> T;

    for(int t = 1; t <= T; t++) {
        cin >> n;

        for(int i = 1; i <= n; i++) {
            g[i].clear();
            root[i] = 1;
        }

        for(int i = 1; i <= n; i++) {
            int u, num, v;
            cin >> u >> num >> v;
            mafia[u] = num;
            for(int j = 1; j <= v; j++) {
                int x;
                cin >> x;
                root[x] = 0;
                g[u].push_back(x);
            }
        }

        int st;
        for(int i = 1; i <= n; i++) {
            if(root[i]) st = i;
        }

        printf("Case %d: %d\n", t, dfs(st,0));
    }

}