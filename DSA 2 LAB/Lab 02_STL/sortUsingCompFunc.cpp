#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define printVec(A) for(auto a: A) cout << a.first << " " << a.second << endl; cout << endl;

bool compPair(pair<int, int> a, pair<int, int> b){
    return a.second/a.first > b.second/b.first;
}

bool comp(int a, int b){
    return a > b;
}

int main(){
    // vector<int> A = {5, 9, 2, 3, 7, 8, 15};

    vector<pair<int, int> > A = {{5, 10}, {3, 9}, {3, 12}, {1, 6}, {5, 5}, {8, 16}};
    cout << ">> Before sorting: " << endl;
    // printVec(A);

    // sort(A.begin(), A.end(), comp);
    sort(A.begin(), A.end(), compPair);
    
    cout << "\n>> After sorting: " << endl;
    for (auto &a: A){
        cout << "a: " << a.first << " b: " << a.second << " ratio: " << a.second/a.first << endl;
    }
    
    


}