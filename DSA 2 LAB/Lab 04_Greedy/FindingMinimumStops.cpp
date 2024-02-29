#include<iostream>
#include<vector>
using namespace std;

int main(){
    int D, M, N;
    cin >> D >> M >> N;
    vector<int> stations(N);
    for(auto &a: stations)
        cin >> a;

    vector<pair<int, int>> stops;
    int prevPos = 0;
    int currPos = 0;
    int travellingDistance = 0;
    for (int i = 0; i < stations.size(); i++){
        currPos = stations[i];

        if(currPos - prevPos > M){
            travellingDistance += stations[i-1] - prevPos;
            prevPos = stations[i-1];
            stops.push_back({i, stations[i-1]});
        }
        
    }

    if(travellingDistance + M >= D){
        for(auto &a: stops){
            cout << "stop at gas station " << a.first << " (" << a.second << " miles)"<< endl;
        }
    } else{
        cout << "Can't reach destination" << endl;
    }
    
}