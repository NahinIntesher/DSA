#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &v, int n) {
    for (int i = 0; i < n - 1; i++) {
        int didSwap = 0;
        for (int j = 0; j < n - i; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j + 1];
                v[j + 1] = v[j];
                v[j] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0) {
            break;
        }
    }
}

int main(){
    int n;
    cout<<"Enter size of the array/vector (n): ";
    cin>>n;
    vector<int> v(n);
    for(auto &a: v){
        cin>>a;
    }
    bubble_sort(v,n);
    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout<<endl;
}