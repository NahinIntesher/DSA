#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of the array/vector (n): ";
    cin>>n;
    vector<int> v(n);
    for(auto &a: v){
        cin>>a;
    }
    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[mini]) {
                mini = j;
            }
        }
        int temp = v[mini];
        v[mini] = v[i];
        v[i] = temp;
    }
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout<<endl;
}