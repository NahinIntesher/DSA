#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;

	int n, count;
	string s;

	for(int i=0; i<T; i++) {
        cin >> n;
        cin >> s;
        count = 0;

        for(int j=0; j<n; j++) {
            if(s[j] == '#') {
                if(s[j-1] == '.' || s[j+1] == '.') {
                    count++;
                }
            }
        }
        printf("Case %d: %d\n", i+1, count);
	}

    return 0;
}
