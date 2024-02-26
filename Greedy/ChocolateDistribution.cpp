#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        int i = 0;
        int j = m - 1;
        long long mini = INT_MAX;
        while(j < n){
            long long diff = a[j] - a[i];
            if(diff < mini)
                mini = diff;
            i++;
            j++;
        }
        return mini;
    }   
};
int main() {
	long long n, m;
	cin >> n;
	vector<long long> a(n);
	for(auto &i: a)
		cin >> i;
	cin >> m;
	Solution ob;
	cout << ob.findMinDiff(a, n, m) << endl;
}