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
bool oneSubsqncEqualtoK(int index, vector<int> A, vector<int> &temp, int k, int sum){
    if(index >= A.size()){
        if(sum == k){
            return true;
        }
        return false;
    }

    // pickup conditions
    temp.push_back(A[index]);
    sum += A[index];
    if(oneSubsqncEqualtoK(index+1, A, temp, k, sum)) return true;
    sum -= A[index];
    temp.pop_back();

    // not pickup conditons
    if(oneSubsqncEqualtoK(index+1, A, temp, k, sum)) return true;

    return false;
}
int main(){
    vector<int> A = {3, 1, 2};
    vector<int> temp;
    int k = 3;
    if(oneSubsqncEqualtoK(0, A, temp, k, 0)){
        cout << "\n>> A Subsequence whose sum is equal to 'K' is: ";
        printVec(temp);
        cout << endl;
    }
    else
        cout << "\n>> There is no subsequences whoose sum is equal to 'K'." << endl;
}
