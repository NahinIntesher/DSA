#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, int E, int source, vector<int> &parent, vector<vector<pair<int, int> > > &adjList){
    vector<int> dis(V, INT_MAX);
    // node, distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;

    dis[source] = 0;
    parent[source] = -1;
    pq.push({source, 0});

    while (!pq.empty()){
        int node = pq.top().first;
        int distance = pq.top().second;
        pq.pop();

        for(auto it: adjList[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;

            if(distance + edgeWeight < dis[adjNode]){
                dis[adjNode] = distance + edgeWeight; 
                pq.push({adjNode, dis[adjNode]});
                parent[adjNode] = node;
            }
        }
    }
    return dis;
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adjList(V + 1);
    vector<int> parent(V, -1);
    for(int i = 1; i <= E; i++){
        int firstNode, secondNode, weight;
        cin >> firstNode >> secondNode >> weight;
        adjList[firstNode].push_back({secondNode, weight});
    }

    int source, dest;
    cin >> source >> dest;
    vector<int> res = dijkstra(V, E, source, parent, adjList);

    // All the distance from source to any node
    cout << "Distances from source to any node: ";
    for(int i = 1; i <= res.size(); i++){
        cout << res[i] << " ";
    } cout << endl;

    // Making Path
    vector<int> path;
    while (dest != source){
        path.push_back(dest);
        dest = parent[dest];
    } path.push_back(dest);

    // Printing the Path
    cout << "Path from source to distance: ";
    for (int i = path.size() - 1; i >= 0; i--){
        cout << path[i];
        if(i != 0) cout << " --> ";
    }

}