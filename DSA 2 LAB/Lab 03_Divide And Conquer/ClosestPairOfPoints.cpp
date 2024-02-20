#include<bits/stdc++.h>
using namespace std;

pair<float, pair<pair<int, int>, pair<int, int> > > closestPairPath(vector<pair<int, int> > A, int low, int high){
    if(low == high){
        return {0.000, {A[low], A[low]}};
    }
    if(low == high){
        float x = A[high].first - A[low].first;
        float y = A[high].second - A[low].second;
        float distance = sqrt(x * x + y * y);
        return {distance, {A[low], A[high]} };
    }
    int mid = (low + high) / 2;
    pair<float, pair<pair<int,int>, pair<int,int>>> p1 = closestPairPath(A, low, mid); 
    pair <float, pair<pair<int,int>, pair<int,int>>> p2 = closestPairPath(A,mid+1, high);

    if(p1.first > p2.first)
        return p1;
    else 
        return p2;
}
int main(){
    int N;
    cin >> N;
    vector<pair<int, int> > A(N);
    for(auto &a: A)
        cin >> a.first >> a.second;
    pair<float, pair<pair<int, int>, pair<int, int> > > p;
    cout << "The closest pair is point (" 
    << p.second.first.first << "," << p.second.first.second << ") and point (" 
    << p.second.second.first << "," << p.second.second.second << ")" << endl;
    cout << "Their distance is " << p.first << endl;
}