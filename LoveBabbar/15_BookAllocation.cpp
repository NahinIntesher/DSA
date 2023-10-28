#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int mid) {
    int i = 0;
    while (m--) {
        int pageSum = 0;
        while((pageSum + arr[i] <= mid) && i < n) {
            pageSum += arr[i];
            i++;
        }
    }
    if(i == n) {
        return true;
    }
    return false;
}

int ayushGivesNinjatest(int n, int m, vector<int> arr) {	
	if(n < m) {
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int start = 0;
    int end = sum;
    int mid;
    int answer = -1;
    while (start <= end) {
        mid = start + (end - start)/2;
        if(isPossible(arr, n, m, mid)) {
            answer = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return answer;
}

int main(){
    int T;
    cin >> T;
    while (T--){
        int N, M;
        cin >> N >> M;
        vector<int> A(N);
        for(auto &a: A){
            cin >> a;
        }
        long long int minOfMaxBook = ayushGivesNinjatest(N, M, A);
        cout << minOfMaxBook << endl;
    }
}