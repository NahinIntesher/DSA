#include<iostream>
#include<vector>
using namespace std;

void printVec(vector<int> A){
    cout << "{";           
    for (int i = 0; i < A.size(); i++){
        if(i == A.size()-1) cout << A[i];
        else cout << A[i] << ",";
    }
    cout << "}" << endl;
}
void subsequences(int index, vector<int> A, vector<int> &temp, int k, int sum){
    if(index >= A.size()){
        if(sum == k){
            printVec(temp);
        }
        return;
    }
    // pickup conditions
    temp.push_back(A[index]);
    sum += A[index];
    subsequences(index+1, A, temp, k, sum);
    sum -= A[index];
    temp.pop_back();

    // not pickup conditons
    subsequences(index+1, A, temp, k, sum);
}

int main(){
    vector<int> A = {3, 1, 2};
    vector<int> temp;
    int k = 3;
    cout << "\n>> Those subsequences whoose sum is equal to 'K' are: " << endl;
    subsequences(0, A, temp, k, 0);
}
