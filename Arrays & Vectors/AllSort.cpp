#include<bits/stdc++.h>
using namespace std;
void printVec(vector<int>& v){
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
void selection_sort(vector<int>& v) {
    for (int i = 0; i < v.size() - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[mini]) {
                mini = j;
            }
        }
        int temp = v[mini];
        v[mini] = v[i];
        v[i] = temp;
    }
}
void insertion_Sort(vector<int>& A){
    int N = A.size();
    for (int i = 1; i < N; i++){
        int key = A[i];
        int j;
        for (j = i - 1; j >= 0; j--){
            if(A[j] > key){
                A[j + 1] = A[j];
            }
        }
        A[j + 1] = key;
    }
}
void bubble_sort(vector<int>& v){
    for (int i = 0; i < v.size() - 1; i++){
        int didSwap = 0;
        for (int j = 0; j < v.size() - 1 - i; j++){
            if(v[j] > v[j + 1]){
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
    cout << "\nEnter size of the array/vector (n): ";
    cin >> n;
    vector<int> A(n);

    // Random number generating and taking input in the vector
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        // v.push_back((rand()%100)+1);
        A[i] = (rand() % 100) + 1;
    }
    // For User input: for(auto &a: v) cin>>a;

    cout << "\n>> Before Using sort: " << "\n";
    printVec(A);
    cout<<endl<<endl;

    // bubble_sort(v);
    selection_sort(A);
    //insertion_Sort(A);

    cout << "\n>> After Using sort: " << "\n";
    printVec(A);
    cout<<endl;
}