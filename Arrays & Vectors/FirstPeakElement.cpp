#include <bits/stdc++.h>
using namespace std;

int findPeakElement(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > arr[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;        
}
int main() {
    int size = 6;
    int arr[] = {1, 3, 8, 12, 4, 2};
    // cin >> size >> target;

    int result = findPeakElement(arr, size);
    cout << result << endl;

    return 0;
}
