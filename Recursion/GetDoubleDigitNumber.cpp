#include<bits/stdc++.h>
using namespace std;

int power(int a, int b){ // pow method gives wrong ans for 10^2. So I made this one
    if(b <= 1) return a;
    return a * power(a, b - 1);
}

int getNumber(int oldNumber, int newNumber){
    if(oldNumber <= 0)
        return newNumber;
    
    int digits = log10(oldNumber); // finding total no of digits in the present number
    int firstDigit = oldNumber / (int)power(10, digits); // finding first digit
    
    if(digits == 0){ // corner case for 1 digit number
        newNumber = newNumber * 10 + oldNumber;
        newNumber = newNumber * 10 + oldNumber;
        oldNumber = 0;
        return newNumber;
    }
    
    newNumber = newNumber * 10 + firstDigit;
    newNumber = newNumber * 10 + firstDigit;

    oldNumber = oldNumber % (int)power(10, digits);
    newNumber = getNumber(oldNumber, newNumber);
    return newNumber;
}

int main(){
    int oldNumber = 1234;
    int newNumber = getNumber(oldNumber, 0);
    cout << "\n>> New Number is: " << newNumber << endl;   
}