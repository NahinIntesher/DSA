#include <bits/stdc++.h>
using namespace std;
bool sortBySecond(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}
int maxMeetings(int start[], int end[], int n){
    vector<pair<int, int>> meetings;
    for(int i = 0; i < n; i++){
        meetings[i].first = start[i];
        meetings[i].second = end[i];
    }
    cout << "hoi";
    sort(meetings.begin(), meetings.end(), sortBySecond);
    int countMeeting = 0;
    for(int i = 0; i < n-1; i++){
        if(meetings[i].second < meetings[i+1].first)
            countMeeting++;
    }
    return countMeeting;
}
int main() {
    int n = 6;
    int start[] = {1,3,0,5,8,5};
    int end[] =  {2,4,6,7,9,9};
    int ans = maxMeetings(start, end, n);
    cout << ans << endl;
}