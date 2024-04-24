#include <bits/stdc++.h>
using namespace std;
struct compare{
    bool operator()(pair<int, pair<int, int>> const &a, pair<int, pair<int, int>> const &b){
        return a.first > b.first;
    }
};

int main(){
    int graph[100][100];
    int vertex, e, w, u, v;
    cin >> vertex >> e;
    for (int i = 0; i < vertex; i++){
        for (int j = 0; j < vertex; j++){
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++){

        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int distance[vertex + 10];
    int visited[vertex + 10];
    int parent[vertex + 10];
    int source;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> q;

    for (int j = 0; j <= vertex; j++){
        visited[j] = 0;
        parent[j] = -1;
        distance[j] = numeric_limits<int>::max();
    }

    cout << "Enter Source: \n";
    cin >> source;
    parent[source] = -1;
    distance[source] = 0;
    visited[source] = 1;

    for (int i = 0; i <= vertex; i++){
        if (graph[source][i] != 0){
            q.push(make_pair(distance[source] + graph[source][i], make_pair(source, i)));
        }
    }
    while (!q.empty()){
        w = q.top().first;
        u = q.top().second.first;
        v = q.top().second.second;
        q.pop();
        if ((visited[v] == 0) && distance[v] > distance[u] + graph[u][v]){
            parent[v] = u;
            distance[v] = distance[u] + graph[u][v];
            for (int i = 1; i <= vertex; i++){
                if (graph[v][i] != 0){
                    q.push(make_pair(distance[v] + graph[v][i], make_pair(v, i)));
                }
            }
            visited[v] = 1;
        }
    }
    for (int i = 0; i <= vertex; i++){
        if (parent[i] != -1)
            cout << parent[i] << " " << i << endl;
    }

    cout << " Enter Destination: \n";
    int dest;
    cin >> dest;
    vector<int> path;
    while (dest != source){
        path.push_back(dest);
        dest = parent[dest];
    }
    path.push_back(dest);
    for (int i = path.size() - 1; i > 0; i--)
        cout << path[i] << " --> ";
    cout << path[0];
}