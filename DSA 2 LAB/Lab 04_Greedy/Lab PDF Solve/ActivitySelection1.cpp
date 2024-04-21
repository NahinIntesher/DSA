#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> activity(N);
    for(auto &a: activity)
        cin >> a.first >> a.second;
    sort(activity.begin(), activity.end(), comp);

    int countAns = 1;
    pair<int, int> lastActivity = activity[0];
    for (int i = 1; i < N; i++){
        if(lastActivity.second < activity[i].first){
            lastActivity = activity[i];
            countAns++;
        }
    }
    cout << countAns;
}