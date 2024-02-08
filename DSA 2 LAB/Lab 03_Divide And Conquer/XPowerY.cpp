#include<iostream>
#include<vector>
using namespace std;

int power(int x, int y){
    if(y == 0) 
        return 1;
    if(y == 1) 
        return x;
    
    if(y % 2 == 0) 
        return power(x, y/2) * power(x, y/2);
    else
        return power(x, y/2) * power(x, y/2) * x;
}

int main(){
    int x, y;
    cin >> x >> y;
    cout << "\n>> x to power y: " << power(x, y);
}