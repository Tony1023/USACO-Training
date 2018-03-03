/*
 ID: tony1021
 PROG: crypt1
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;
#define FOR(i,j) for (int i = 0; i < j; ++i)
bool isCrypt(int, int, int[]);

int main() {
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    int N, dig[10];
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> dig[i];
    
    int count = 0;
    FOR(i, N) {
        FOR(j, N) {
            FOR(k, N) {
                FOR(l, N) {
                    FOR(m, N){
                        int op = dig[i]*100 + dig[j]*10 + dig[k];
                        int pProduct1 = op * dig[m], pProduct2 = op * dig[l];
                        if (pProduct1 > 999 || pProduct1 < 100 || pProduct2 > 999 || pProduct2 < 100)
                            continue;
                        if (isCrypt(pProduct1, N, dig) && isCrypt(pProduct2, N, dig)) {
                            int product = pProduct1 * 10 + pProduct2;
                            if (product > 9999 || product < 1000)
                                continue;
                            if (isCrypt(product, N, dig)){
//                                cout << pProduct1 << " " << pProduct2 << " " << product << endl;
                                ++count;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << count << endl;
    
    
    return 0;
}

bool isCrypt(int num, int N, int dig[]) {
    bool ret = true;
    while (num > 0) {
        int digit = num % 10;
        num /= 10;
        bool check = false;
        FOR(i, N) {
            if (dig[i] == digit)
                check = true;
        }
        ret = ret && check;
    }
    return ret;
}
