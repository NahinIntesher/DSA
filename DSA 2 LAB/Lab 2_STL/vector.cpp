#include<iostream>
#include<vector>
using namespace std;

int main(){
    /* initialization - way 1 */
    vector<int> list2 = {1, 10, 200};
    /* initialization - way 2 */
    vector<int> list4;

    /* input taking - way 1 */
    for (int i = 0; i < 5; i++){
        int x;
        cin >> x;
        list4.push_back(x);
    }

    /* input taking - way 2 */
    // for (auto &a: list4){
    //     cin >> a;
    // }

    /* size of vector */
    cout << "Size: " << list4.size();

    /* iterate over vector - way 1 */
    for (int i = 0; i < list4.size(); i++){
        cout << "["<< i << "] " << list4[i] << endl;
    } cout << endl;

    /* delete from indx i */
    int i = 2;
    list4.erase(list4.begin() + i);

    /* iterate over vector - way 2 */
    for(auto it = list4.begin(); it != list4.end(); it++){
        cout << *it << " ";
    } cout << endl;

    /* iterate over vector - way 3 */
    for(int x: list4){
        cout << x << " ";
    }
}