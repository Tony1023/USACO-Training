/*
 ID: tony1021
 PROG: hamming
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int N, B, D;
bool codes[65][8], solved = false;
void find(int);
bool isHamDist(int);
void printAns(int);
inline int quickPow2(int);

int main() {
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    cin >> N >> B >> D;
    memset(codes, false, sizeof(codes));
    find(0);
    return 0;
}

inline int quickPow2(int pow) {
    int pows[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    return pows[pow];
}
void printAns(int n) {
    for (int i = 0; i < n; ++i) {
        int codeword = 0;
        for (int j = 0; j < B; ++j) {
            if (codes[i][j])
                codeword += quickPow2(j);
        }
        cout << codeword;
        if (i == n - 1) {
            cout << endl;
            return;
        }
        if (i % 10 == 9)
            cout << "\n";
        else
            cout << " ";
    }
}
bool isHamDist(int n) {
    int dist;
    for (int i = 0; i < n; ++i) {
        dist = 0;
        for (int j = 0; j < B; ++j)
            dist += (codes[n][j] != codes[i][j]); //if the jth bit does not equal, add one hamming dist.
        if (dist < D)
            return false;
    }
    return true;
}
void find(int n) { // This starts from 1.
    if (n == N) { // 0 thru N has been found.
        printAns(n);
        solved = true;
        return;
    }
    //Generate the next bit.
    bool carry = true;
    if (n != 0) {
        for (int i = 0; i < B; ++i) {
            if (carry) {
                carry = codes[n - 1][i];
                codes[n][i] = !codes[n - 1][i];
            } else
                codes[n][i] = codes[n - 1][i];
        }
    }
    do { //keep increamenting this bit
        if (isHamDist(n)) {
            find(n + 1);
            if(solved)
                return;
        }
        carry = true;
        for (int i = 0; i < B; ++i) {
            if (carry) {
                carry = codes[n][i];
                codes[n][i] = !codes[n][i];
            } else
                break;
        }
    } while (!solved);
}
