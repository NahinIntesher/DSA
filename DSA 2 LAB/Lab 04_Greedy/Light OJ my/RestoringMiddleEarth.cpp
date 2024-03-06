#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int n, k;
        cin >> n >> k;

        vector<int> capacities(n);
        for (int i = 0; i < n; i++) {
            cin >> capacities[i];
        }

        // Sort the capacities in descending order
        sort(capacities.begin(), capacities.end(), greater<int>());

        long long total_cost = 0;
        int current_population = 0;

        for (int i = 0; i < n; i++) {
            current_population += capacities[i];
            // Calculate the cost if we split the current population into groups of size up to k
            total_cost += (current_population / k) * (i + 1);
            current_population %= k;
        }

        cout << "Case " << tc << ": " << total_cost << endl;
    }

    return 0;
}
