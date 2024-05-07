#include<bits/stdc++.h>
using namespace std;

int n_edge, n_vertex, p[100], rankk[100];

void make_set(){
    for (int i = 0; i < n_vertex; i++){
        p[i] = i;
        rankk[i] = 0;
    }    
}
int find_set(int x){
    if(p[x] = x)
        return x;
    else 
        return p[x] = find_set(p[x]);
}
int union_set(int s1, int s2){
    int r1 = find_set(s1);
    int r2 = find_set(s2);
    if(r1 == r2)
        return 0; // already in same set
    if(rankk[r1] > rankk[r2]){
        r2 = r1;
    } else{
        p[r1] = r2;
        if(rankk[r1] == rankk[r2]) 
            rankk[r1]++;
    }
    return 1;
}

int main(){
    vector<pair<int, pair<int, int> > > graph1;
    int i, u, v, w;
    cout << "Enter Number of Vertices: " << endl;
    cin >> n_vertex;
    cout << "Enter Number of Edges: " << endl;
    cin >> n_edge;
    cout << "Enter the graph: " << endl;
    for (int i = 0; i < n_edge; i++){
        cin >> u >> v >> w;
        graph1.push_back({w, {u, v}});
    }
    sort(graph1.begin(), graph1.end());
    cout << "Sorted Graph according to the Edges: " << endl;
    for (int i = 0; i < n_edge; i++){
        cout << "<" << graph1[i].second.first << "," 
        << graph1[i].second.second << "> --> " << graph1[i].first << endl; 
    }
    cout << endl;
    
    // Making each node
    make_set();

    cout << "Minimum Spaning Tree: " << endl;
    for (int i = 0; i < n_edge; i++){
        u = graph1[i].second.first;
        v = graph1[i].second.second;
        if(union_set(u, v) != 0){
            cout << "<" << u << ", " << v << "> --> " <<  graph1[i].first << endl;
        }
    }

}

// Pseudo code of Kruskal