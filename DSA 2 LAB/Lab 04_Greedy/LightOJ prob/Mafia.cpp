#include <bits/stdc++.h>
using namespace std;

const int n=10005;

int par[n],mafia[n],ans;
bool vis[n];
vector <int> adj[n];
int Find_Root(int u) {
    if(u==par[u]) return u;
    else Find_Root(par[u]);
}
int dfs(int u) {
    vis[u]=1;
    int total=mafia[u]-1,i,sz=adj[u].size(),v;
    for(i=0; i<sz; i++) {
        v=adj[u][i];
        if(!vis[v]) {
            int x=dfs(v);
            total+=x;
            ans+=abs(x);
        }
    }

    return total;

}
int main() {
    int cs,t;
    scanf("%d",&t);
    for(cs=1; cs<=t; cs++) {
        int i,n;
        scanf("%d",&n);
        for(i=1; i<=n; i++) {
            adj[i].clear();
            vis[i]=0;
            par[i]=i;
        }
        for(i=1; i<=n; i++) {
            int v,w,j;

            scanf("%d %d %d",&v,&mafia[i],&w);
            for(j=0; j<w; j++) {
                int a;
                scanf("%d",&a);
                adj[v].push_back(a);
                adj[a].push_back(v);
                par[a]=v;
            }
        }
        int root=Find_Root(1);
        ans=0;
        dfs(root);
        printf("Case %d: %d\n",cs,ans);

    }

    return 0;
}
