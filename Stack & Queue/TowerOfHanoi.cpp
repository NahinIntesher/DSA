#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int N, char start, char auxilary, char distance){
    if(N == 0) 
        return; 

    towerOfHanoi(N - 1, start, distance, auxilary);
    cout << start << " -> " << distance << endl;
    towerOfHanoi(N - 1, auxilary, start, distance);
    return;
}
int main(){
    int N;
    cout << endl << "-> Enter number of disc: ";
    cin >> N; 
    cout << "-> No of Moves: " << (2 << (N-1)) - 1 << endl;
    towerOfHanoi(N, 'A', 'B', 'C');
}
