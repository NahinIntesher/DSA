#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges , int n , int m, int s , int t){
    
	// Make Adjacency List
	unordered_map<int, list<int>> adjList;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        // adjList[v].push_back(u);
    }
	
	// Do BFS9
	vector<bool> visited(n+1, 0);
	vector<int> parent(n+1, 0);
	queue<int> q;
	
	q.push(s);
	parent[s] = -1;
	visited[s] = true;

	while (!q.empty()){
		int frontNode = q.front();
		q.pop();

		for(auto neighbour: adjList[frontNode]){
			if(!visited[neighbour]){
				q.push(neighbour);
				visited[neighbour] = true;
				parent[neighbour] = frontNode;
			}
		}
	}

	// Prepare Shortest path
	vector<int> shortestPath;
	int currentNode = t;
	shortestPath.push_back(currentNode);

	while(currentNode != s){
		currentNode = parent[currentNode];
		shortestPath.push_back(currentNode);
	}
	reverse(shortestPath.begin(), shortestPath.end());
	return shortestPath;
}

class Graph{
    public:
    unordered_map<int, list<pair<int, int> > > adj;
    void addEdge(int u, int v, int weight){
        pair<int, int> p = {v, weight};
        adj[u].push_back(p);
    }
    void printAdj(){
        for(auto i: adj){
            cout << i.first <<"-> ";
            
        }
    }




};

int main(){
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);






}