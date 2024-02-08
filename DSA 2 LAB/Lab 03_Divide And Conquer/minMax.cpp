#include<iostream>
#include<vector>
using namespace std;

pair<float, float> minMax(vector<float> A, int start, int end){
    if(start == end){
        return {A[start], A[end]};
    }

    int mid = (start + end) / 2;
    pair<float, float> right = minMax(A, start, mid);
    pair<float, float> left = minMax(A, mid+1, end);

    pair<float, float> ans;
    ans.first = min(right.first, left.first);
    ans.second = max(right.second, left.second);

    return ans;
}

int main(){
    // int N;
    // cin >> N;
    vector<float> A = {34, -1.5, 5, 6, -50.1, -6};
    // for(auto &a: A)
    //     cin >> a;

    pair<float, float> ans = minMax(A, 0, A.size()-1);
    cout << "\n>> Min: " << ans.first << ", Max: " << ans.second;
}