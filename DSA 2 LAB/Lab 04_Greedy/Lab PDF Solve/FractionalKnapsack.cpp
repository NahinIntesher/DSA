#include<bits/stdc++.h>
using namespace std;

float mini(float a, float b){
    return (a < b ? a : b);
}
bool comp(pair<int, pair<float, float>> a, pair<int, pair<float, float>> b){
    return (a.second.second/a.second.first > b.second.second/b.second.first);
}
void knapsack(vector<pair<int, pair<float, float>>> items, float capLeft){
    float profit = 0;
    for (int i = 0; i < items.size(); i++){
        if(capLeft <= 0) break;

        int id = items[i].first;
        float weight = items[i].second.first;
        float value = items[i].second.second;

        float fraction = mini(1.0, capLeft/weight);
        capLeft -= fraction * weight;
        profit += fraction * value;

        printf("item %d: %.1f kg %.1f taka\n", id, fraction*weight, fraction*value);
    }
    cout << "profit: " << profit << " taka" << endl;
}

int main(){
    int N, W;
    cin >> N;
    vector<pair<int, pair<float, float>>> items(N);
    for(int i = 0; i < N; i++){
        items[i].first = i+1;
        cin >> items[i].second.first >> items[i].second.second; 
    }
    cin >> W;
    sort(items.begin(), items.end(), comp);
    // for(auto &a: items){
    //     cout << a.first << " " << a.second.first << " " << a.second.second << endl;
    // }
    knapsack(items, W);
}