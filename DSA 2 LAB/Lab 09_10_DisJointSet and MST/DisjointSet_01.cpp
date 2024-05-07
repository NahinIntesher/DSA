#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int parent[11];
void makeSet(int x) {
    parent[x] = x;
}
int findSet(int x) {
    if (x != parent[x])
        return findSet(parent[x]);
    return parent[x];
}
void unionSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b)
        parent[b] = a;
}
int main(){
    int element [] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 1; i < 10; i++){
        makeSet(i); 
    }
    unionSets(1, 2); unionSets(3, 5); unionSets(4, 6);
    unionSets(5, 6); unionSets(7, 9); unionSets(8, 9);

    cout << "Parent of 4: " << findSet(4) << endl;
    cout << "Parent of 8: " << findSet(8) << endl;
    
    for (int i = 1; i < 10; i++){
        cout << parent[i] << " ";
    } cout << endl;
    int component = 0;
    for (int i = 1; i < 10; i++){
        if(parent[i] == i)
            component++;
    }
    cout << "Conected Components: " << component << endl;
}