/*
 ID: tony1021
 PROG: money
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int V, N, coins[25];
long long m[10001];

int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    cin >> V >> N;
    memset(m, 0, sizeof(m));
    for (int i = 0; i < V; ++i)
        cin >> coins[i];
    m[0] = 1;
    
    for (int i = V - 1; i >= 0; --i)
        for (int j = coins[i]; j <= N ; ++j)
            m[j] += m[j - coins[i]];
    cout << m[N] << endl;
    
    return 0;
}
