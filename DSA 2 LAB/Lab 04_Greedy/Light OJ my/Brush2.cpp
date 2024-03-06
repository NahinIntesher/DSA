/* BRUSH 2:  
After the long contest, Samee returned home and got angry after seeing his room dusty. Who likes to see a dusty room after a brain storming programming contest? After checking a bit he found a brush in his room which has width w. Dusts are defined as 2D points. And since they are scattered everywhere, Samee is a bit confused what to do. So, he attached a rope with the brush such that it can be moved horizontally (in X axis) with the help of the rope but in straight line. He places it anywhere and moves it. For example, the y co-ordinate of the bottom part of the brush is 2 and its width is 3, so the y coordinate of the upper side of the brush will be 5. And if the brush is moved, all dusts whose y co-ordinates are between 2 and 5 (inclusive) will be cleaned. After cleaning all the dusts in that part, Samee places the brush in another place and uses the same procedure. He defined a move as placing the brush in a place and cleaning all the dusts in the horizontal zone of the brush.

You can assume that the rope is sufficiently large. Now Samee wants to clean the room with minimum number of moves. Since he already had a contest, his head is messy. So, help him. 

Input:
Input starts with an integer T (≤ 15), denoting the number of test cases.
Each case starts with a blank line. The next line contains two integers N (1 ≤ N ≤ 50000) and w (1 ≤ w ≤ 10000), means that there are N dust points. Each of the next N lines will contain two integers: xi yi, denoting coordinates of the dusts. You can assume that (-109 ≤ xi, yi ≤ 109) and all points are distinct.

Output
For each case print the case number and the minimum number of moves.

*/

#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
void solve(int Case) {
    int N, W;
    cin >> N >> W;
    vector<pair<int, int>> A(N);
    for(auto &a: A){
        cin >> a.first >> a.second;
    }
    sort(A.begin(), A.end(), comp);
    int moves = 1;
    int start = A[0].second;
    for (int i = 1; i < A.size(); i++){
        if(start+W < A[i].second){
            moves++;
            start = A[i].second; // take the brush to the next point
        }
    }
    cout << "Case " << Case << ": " << moves << endl;

}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(i);    
    }
}
