#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    // int N;
    // cin >> N;
    vector<int> A = {5, 9, 2, 3, 7, 8, 15};

    // for (auto &a: A)
    //     cin >> a;

    sort(A.begin() + 2, A.begin() + 6);
   
    for(int a: A){
        cout << a << " ";
    } cout << endl;

    sort(A.begin() + 2, A.begin() + 6, greater<int>());
    
    for(int a: A){
        cout << a << " ";
    }



}