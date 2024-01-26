#include<bits/stdc++.h>
using namespace std;

int reverseNumber(int oldNumber, int newNumber){
    if(oldNumber <= 0) 
        return newNumber;
    
    newNumber = newNumber * 10 + oldNumber % 10;
    oldNumber = oldNumber / 10;

    newNumber = reverseNumber(oldNumber, newNumber);
    return newNumber;
}

int main(){
    int oldNumber = 123454321;
    int newNumber = reverseNumber(oldNumber, 0);
    cout << "\n>> Reverse Number is: " << newNumber << endl;
    
    if(oldNumber == newNumber)
        cout << "Number is a palindrome.";
    else 
        cout << "The number is not a palindrome.";
}