#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges , int n , int m, int s , int t){
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
	
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
	// for(int i = 1; i < parent.size(); i++){
	// 	cout << parent[i] << " ";
	// }

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

int main(){
    int v = 8, e = 9;
    vector<pair<int, int>> edges = {{1,2},{1,3},{1,4},{2,5},{3,8},{4,6},{5,8},{6,7},{7,8}};

    vector<int> ans = shortestPath(edges , v , e, 1 , 8);

	for(auto i: ans){
		cout << i << " ";
	}

}