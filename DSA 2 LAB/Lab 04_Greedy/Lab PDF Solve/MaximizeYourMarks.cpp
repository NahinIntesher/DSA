#include <bits/stdc++.h>
using namespace std;

float mini(float a, float b){
    return (a < b ? a : b);
}
bool comp(pair<int, pair<float, float>> a, pair<int, pair<float, float>> b){
    return (a.second.first/a.second.second > b.second.first/b.second.second);
}
void maxMark(vector<pair<int, pair<float, float>>> &question, float timeLeft){
    sort(question.begin(), question.end(), comp);
    int N = question.size();
    int i = 0;
    int totalMark = 0;
    while(timeLeft > 0 && i < N){
        if(timeLeft <= 0) break;

        int id = question[i].first;
        float mark = question[i].second.first;
        float time = question[i].second.second;

        float fraction = mini(1.0, timeLeft/time);
        timeLeft -= fraction * time;
        totalMark += fraction * mark;

        cout << "ques " << id << " " << fraction*100 << "% done -- " << fraction * mark << " marks" << endl;
        i++;
    }
    cout << "Maximum " << totalMark << " marks answering alone";
}

int main(){
    int M, T, N;
    cin >> M >> T >> N;
    vector<pair<int, pair<float, float>>> question(N);
    for(int i = 0; i < N; i++){
        question[i].first = i+1;
        cin >> question[i].second.first >> question[i].second.second; 
    }
    maxMark(question, T);
}