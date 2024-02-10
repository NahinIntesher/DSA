#include<iostream>
#include<vector>
#include <utility>
#include <climits>
using namespace std;

/* {maxSum , {startIndex, endIndex}} */
pair<int, pair<int, int>> maxSumCross(vector<int> &A, int start, int end, int mid){
    int maxLeft = -100, maxRight = -100;
    int sumLeft = 0, sumRight = 0;
    int leftIndex = mid, rightIndex = mid+1;
    for (int i = mid; i >= start; i--){
        sumLeft += A[i];
        if(sumLeft > maxLeft){
            maxLeft = sumLeft;
            leftIndex = i;
        }
    }
    for (int i = mid+1; i <= end; i++){
        sumRight += A[i];
        if(sumRight > maxRight){
            maxRight = sumRight;
            rightIndex = i;
        }
    }
    return {maxLeft+maxRight, {leftIndex, rightIndex}};
}

/* {maxSum , {startIndex, endIndex}} */
pair<int, pair<int, int>> maxSum(vector<int> &A, int start, int end){
    if(start == end){
        return {A[start], {start, end}};
    }
    int mid = start + (end - start) / 2;

    pair<int, pair<int, int>> right = maxSum(A, start, mid);
    pair<int, pair<int, int>> left = maxSum(A, mid + 1, end);
    pair<int, pair<int, int>> cross = maxSumCross(A, start, end, mid);

    if(right.first > left.first && right.first > cross.first)
        return right;
    else if(left.first > right.first && left.first > cross.first)
        return left;
    else 
        return cross;
}

int main(){
    vector<int> A = {1, 2, -3, -4, 5, 6, -7, -8, -9};

    pair<int, pair<int, int>> ans = maxSum(A, 0, A.size()-1);
    cout << "\n>> Max Sum: " << ans.first << endl;
    cout << "\n>> Sub Array is: ";
    for (int i = ans.second.first; i <= ans.second.second; i++){
        cout << A[i] << " ";
    } cout << endl << endl;
}
