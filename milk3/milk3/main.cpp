/*
 ID: tony1021
 PROG: milk3
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int capacity[3];
bool stateOccured[21][21][21];
bool C_state[21];
void pour(int,int,int);

int main() {
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    memset(stateOccured, false, sizeof(stateOccured));
    memset(C_state, false, sizeof(C_state));
    for (int i = 0; i < 3; ++i)
        cin >> capacity[i];
    pour(0, 0, capacity[2]);
    bool isFirst = true;
    for (int i = 0; i < 21; ++i) {
        if (C_state[i]) {
            if (isFirst){
                cout << i;
                isFirst = false;
            }
            else
                cout << " " << i;
        }
    }
    cout << endl;
    return 0;
}

void pour(int a, int b, int c) {
    stateOccured[a][b][c] = true;
    if (a == 0)
        C_state[c] = true;
    int milk[3] = {a, b, c};
    for (int from = 0; from < 3; ++from)
        for (int to = 0; to < 3; ++to) {
            if (from == to)
                continue;
            if (milk[from] == 0)
                continue;
            if (milk[from] < capacity[to] - milk[to]) { //can pour all the milk
                milk[to] += milk[from];
                milk[from] = 0;
            }
            else { //just can fill the to bucket
                milk[from] -= (capacity[to] - milk[to]);
                milk[to] = capacity[to];
            }
            
            if (!stateOccured[milk[0]][milk[1]][milk[2]])
                pour(milk[0], milk[1], milk[2]);
            milk[0] = a; milk[1] = b; milk[2] = c; //reset the state
        }
}
