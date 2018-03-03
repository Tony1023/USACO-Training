/*
 ID: tony1021
 PROG: wormhole
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int X[12], Y[12], N, paired[12];
int solve();
bool cycleExist();

int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> X[i] >> Y[i];
    memset(paired, -1, sizeof(paired));
    
    cout << solve() << endl;
    
    return 0;
}

int solve() {
    //find the first not paired
    int first, count = 0;
    for (first = 0; first < N; ++first)
        if (paired[first] == -1)
            break;
    
    //every hole paired: will return 1 for yes and 0 for no
    if (first == N)
        return cycleExist();
    
    //find the next unpaired
    for (int second = first + 1; second < N; ++second) {
        if (paired[second] == -1) {
            paired[first] = second;
            paired[second] = first;
            count += solve();
            paired[first] = paired[second] = -1;
        }
    }
    
    return count;
    
}
bool cycleExist() {
//    return true;
    for (int i = 0; i < N; ++i) {
        int in = i, out, count = 0;
        do {
            //get out from the paired wormhole
            out = paired[in];
            in = -1; //presumably no next entrance
            int j;
            for (j = 0; j < N; ++j) {
                if (j == out)
                    continue;
                if (Y[j] == Y[out] && X[j] > X[out]) { //there is at least one hole to the right
                    if (in == -1)
                        in = j;
                    else
                        in = X[in] < X[j] ? in : j; // choose the nearest to enter
                    ++count;
                }
            }
            if (count > 144)
                return true;
        } while (in != -1);
    }
    return false;
}















