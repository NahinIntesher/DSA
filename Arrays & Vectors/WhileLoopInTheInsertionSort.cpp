#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int>& v){
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void insertion_Sort(vector<int>& A){
    int N = A.size();
    for (int j = 0; j < N; j++){
        int t = A[j];
        int i = j - 1;
        int count = 0;
        while (i >= 0 && A[i] < t){
            count++;
            cout << "J: " << j << ", While Loop(true): " << count << endl;
            // cout << "A[i]: " << A[i] << ", A[j]: " << A[j] << endl << endl;
            A[i + 1] = A[i];
            i--;
        }
        cout << "J: " << j << ", While Loop(false): " << ++count << endl << endl;
        A[i + 1] = t;
    }
}

int main(){
    vector<int> A = {30, 10, 40, 20, 15};
    vector<int> B = {10, 15, 20, 30, 40};
    vector<int> C = {40, 30, 20, 15, 10};

    cout << "\n-> Before Using sort: " << "\n";
    printVec(C);
    cout<<endl<<endl;
    
    insertion_Sort(C);
    
    cout << "\n-> After Using sort: " << "\n";
    printVec(C);
    cout<<endl;
}