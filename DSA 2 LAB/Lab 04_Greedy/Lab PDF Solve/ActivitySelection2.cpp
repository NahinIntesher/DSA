#include<bits/stdc++.h>
using namespace std;
bool comp(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b){
    int endA = a.second.first + a.second.second;
    int endB = b.second.first + b.second.second;
    return endA < endB;
}
void activitySelection(vector<pair<string, pair<int, int>>> &activity, int cleanTime){
    int N = activity.size();
    int countAns = 1;
    vector<string> ans;
    pair<int, int> lastActivity = activity[0].second;
    ans.push_back(activity[0].first);
    for (int i = 1; i < N; i++){
        // end = start + duration
        int lastActivityEndTime = lastActivity.first + lastActivity.second; 
        if(lastActivityEndTime + cleanTime <= activity[i].second.first){
            ans.push_back(activity[i].first);
            lastActivity = activity[i].second;
            countAns++;
        }
    }
    cout << "Chosen clubs: " << endl;
    for(auto &a: ans){
        cout << a << endl;
    }
}
int main(){
    int N, X;
    cin >> N;
    vector<pair<string, pair<int, int>>> activity(N);
    for(int i = 0; i < N; i++){
        cin >> activity[i].first >> activity[i].second.first >> activity[i].second.second; 
    }
    cin >> X;
    sort(activity.begin(), activity.end(), comp);
    // for(auto &a: activity){
    //     cout << a.first << " " << a.second.first << " " << a.second.second << endl;
    // }
    activitySelection(activity, X);
    
}