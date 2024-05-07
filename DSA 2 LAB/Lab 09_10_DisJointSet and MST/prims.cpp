#include<bits/stdc++.h>
using namespace std;
struct compare{
    bool operator()(pair<int, pair<int, int>> const &a, pair<int, pair<int,int>> const &b){
        return a.first > b.first;
    }
};



int main(){
    int graph[100][100];
    int n_vertex, n_edge;
    int u, v, w;
    cin >> n_vertex >> n_edge;
    for (int i = 0; i < n_vertex; i++){ // initialize 2D matrix
        for (int j = 0; j < n_vertex; j++){
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < n_edge; i++){ // input graph
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
   
    int visited[n_vertex + 10];
    int parent[n_vertex + 10];
    int distance[n_vertex + 10];
    for (int i = 0; i < n_vertex; i++){
        visited[i] = 0;
        parent[i] = -1;
        distance[i] = INT_MAX;
    }
   
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>> , compare> queue_edges;  
    // PRIM'S ALGORITHM BEGINS HERE :
    int source;
    // cout << "Enter source: ";
    cin >> source;
    parent[source] = 0;
    distance[source] = 0;
    visited[source] = 1;

    for (int i = 1; i <= n_vertex; i++){
        if(graph[source][i] != 0){
            queue_edges.push({graph[source][i], {source, i}});
        }
    }
    
    while (!queue_edges.empty()){
        w = queue_edges.top().first;
        u = queue_edges.top().second.first;
        v = queue_edges.top().second.second;
        queue_edges.pop();

        if(visited[v] == 0 && distance[v] > graph[u][v]){
            parent[v] = u;
            distance[v] = graph[u][v];

            for (int i = 1; i <= n_vertex; i++){
                if(graph[v][i] != 0){
                    queue_edges.push({graph[v][i], {v, i}});
                }
            }
            visited[v] = 1; 
        }

    }
    
    for (int i = 1; i <= n_vertex; i++){
        cout << parent[i] << " " << i << graph[i][parent[i]] << endl;
    }
    
    
}

/*

input:

8 10
1 3 6
1 2 14 
1 4 10
1 5 5
2 4 3
3 5 4
4 6 3
5 6 2
5 7 9
6 8 15

*/