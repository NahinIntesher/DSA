#include <bits/stdc++.h>
using namespace std;

struct comp{
    bool operator()(string s1, string s2){
        int asci1 = 0, asci2 = 0;
        for (int i = 0; i < s1.size(); i++)
            asci1 += (int)s1[i];
        for (int i = 0; i < s2.size(); i++)
            asci2 += (int)s2[i];
        return asci1 > asci2;
    }
};
int main(){
    int N;
    cin >> N;
    priority_queue<string, vector<string>, comp> pq;
    for(int i = 0; i < N; i++){    
        string s;
        cin >> s;
        pq.push(s);
    }
    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }
}

/*

-> What I understand: I have to take all the string in a Priority Queue that will take 
    input according to the length of the ascii value of the string

-> My approach: I made a custom compare function that is implemented at the time of
    I have decleared Priority Queue which will take input into itself according to
    the lesser ascii value

-> Key Logic: Custom Compare function will take the strings and push them into the 
    Priority Queue. Mainly custom compare function is the thing that will do the main 
    thing. Then I nomally print the Priority Queue.

*/