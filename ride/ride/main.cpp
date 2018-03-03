/*
ID: tony1021
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
    
    freopen("ride.out", "w", stdout);
    freopen("ride.in", "r", stdin);
    
    string comet;
    string group;
    
    cin >> comet;
    cin >> group;
    
    int comet_product = 1;
    int group_product = 1;
    
    for (string::iterator iter = comet.begin(); iter != comet.end(); ++iter) {
        comet_product *= int(*iter) - 64;
    }
    for (string::iterator iter = group.begin(); iter != group.end(); ++iter) {
        group_product *= int(*iter) - 64;
    }
    
//    cout << comet_product << " " << group_product << endl;
    
    if ((comet_product - group_product) % 47 == 0) {
        cout << "GO\n";
    } else {
        cout << "STAY\n";
    }
    
    return 0;
}
