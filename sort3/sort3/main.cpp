/*
 ID: tony1021
 PROG: sort3
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int N, num[1000], freq[3], exchange[3][3]; //[i][j] means the number of i in j's place.
void locate();
int solve();

int main() {
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    cin >> N;
    memset(freq, 0, sizeof(freq));
    memset(exchange, 0, sizeof(exchange));
    for (int i = 0; i < N; ++i) {
        cin >> num[i];
        ++freq[--num[i]];
    }
    locate();
    cout << solve() << "\n";
    return 0;
}

int solve() {
    int total = 0;
    //exchange 1 with 2 and 3, and 2 with 3.
    for (int ex1 = 0; ex1 < 3; ++ex1) {
        for (int ex2 = ex1 + 1; ex2 < 3; ++ex2) {
            int excNum = min(exchange[ex1][ex2], exchange[ex2][ex1]);
            total += excNum;
            exchange[ex1][ex2] -= excNum;
            exchange[ex2][ex1] -= excNum;
            exchange[ex1][ex1] += excNum;
            exchange[ex2][ex2] += excNum;
//            for (int i = 0; i < 3; ++i) {
//                for (int j = 0; j < 3; ++j)
//                    cout << exchange[i][j] << " ";
//                cout << "\n";
//            }
        }
    }
    //these are the changes that need two operations, such as 123 to 312
    total += 2 * (exchange[0][1] + exchange[0][2]);
    return total;
}
void locate() {
    int i = 0;
    while (i < freq[0]) {
        ++exchange[num[i]][0];
        ++i;
    }
    while (i < freq[0] + freq[1]) {
        ++exchange[num[i]][1];
        ++i;
    }
    while (i < freq[0] + freq[1] + freq[2]) {
        ++exchange[num[i]][2];
        ++i;
    }
}
