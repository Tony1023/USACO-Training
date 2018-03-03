/*
 ID: tony1021
 PROG: subset
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int N, halfSum;
long long int d[1000]; //d[i]combinations summing to i

int main() {
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    cin >> N;
    
    int SUM = N * (N + 1) / 2;
    if (SUM % 2 != 0) {
        cout << 0 << endl;
        return 0;
    } else {
        halfSum = SUM / 2;
    }
    memset(d, 0, sizeof(d));
    d[0] = 1;
    for (int i = 1; i <= N; ++i) 
        for (int j = i * (i + 1) / 2; j >= i; --j)
            d[j] += d[j - i]; // total combinations += combinations summing to j - i
    cout << d[halfSum] / 2 << endl;
    return 0;
}
