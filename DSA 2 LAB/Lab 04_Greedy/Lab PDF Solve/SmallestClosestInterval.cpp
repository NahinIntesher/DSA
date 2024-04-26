#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<double> points(N);
    for(auto &a: points) {
        cin >> a;
    }

    sort(points.begin(), points.end());
    cout << endl << "("<< points[0] << ", " << points[N - 1] << ")";

}