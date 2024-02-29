#include<bits/stdc++.h>
using namespace std;
float mini(float a, float b){
    return (a < b ? a : b);
}
bool comp(pair<string, pair<float, float>> a, pair<string, pair<float, float>> b){
    if(a.second.second == 0)
        return true;
    if(b.second.second == 0)
        return true;
    return (a.second.first/a.second.second > b.second.first/b.second.second);
}
void knapsack(vector<pair<string, pair<float, float>>> &items, float capLeft, int index){
    sort(items.begin(), items.end(), comp);
    float profit = 0;
    for (int i = 0; i < items.size(); i++){
        if(capLeft <= 0) break;

        string name = items[i].first;
        float value = items[i].second.first;
        float weight = items[i].second.second;

        if(weight == 0) continue;

        float fraction = mini(1.0, capLeft/weight);
        capLeft -= fraction * weight;
        profit += fraction * value;

        items[i].second.second -= fraction * weight; // important line
        items[i].second.first -= fraction * value; // important line
        
        cout << "Taking " << name << ": ";
        printf("%.1f kg %.1f taka\n", fraction*weight, fraction*value);
    }
    printf("Thief %d profit: %.1f taka\n\n", index, profit);

    // cout << "Thief " << index << " profit: " << profit << " taka" << endl << endl;
}

int main(){
    int N, K;
    cin >> N;
    vector<pair<string, pair<float, float>>> items(N);
    for(int i = 0; i < N; i++){
        cin >> items[i].first >> items[i].second.first >> items[i].second.second; 
    }
    cin >> K;
    vector<int> theifs(K);
    for(auto &a: theifs){
        cin >> a;
    }

    int totalTheives = 0;
    for (int i = 0; i < theifs.size(); i++){
        /* check if weight of any(more precisely last) element remains 
        then no of theif will increase by 1 */
        // if(items[items.size()-1].second.second != 0)
            totalTheives++;
        knapsack(items, theifs[i], i+1);
    }
    
    cout << "Total " << totalTheives << " thieves stole from the warehouse" << endl;
    bool left = false;
    for(auto &a: items){
        if(a.second.second != 0){
            left = true;
            break;
        }
    }
    if(left){
        cout << "Still following items are left" << endl;
        for(int i = 0; i < items.size(); i++){
            if(items[i].second.second != 0){
                cout << items[i].first;
                printf(" %.1f kg %.1f taka\n", items[i].second.second, items[i].second.first);
            }
        }
    }
    
}