#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of the array/vector (n): ";
    cin>>n;
    vector<int> v(n);
    for(int i = 1; i < n; i++){
        int a;
        if (cin.fail()) {
            cerr << "Error: Invalid input. Please enter a valid integer.";
            return 0;
        }
        cin>>a;
    }
    for (int i = 1; i < v.size(); i++){
        int key = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > key){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout<<endl;
}