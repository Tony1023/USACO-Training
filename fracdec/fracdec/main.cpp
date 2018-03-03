/*
 ID: tony1021
 PROG: fracdec
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;
typedef vector<int> vint;
vint vec;
int rem[100001];
int N, D;
int start = -1;
void solve(int,int);

int main() {
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
    cin >> N >> D;
    memset(rem, 0, sizeof(rem));
    
    int quotient = N / D, remainder = N % D;
    for (int num = 1; rem[remainder] == 0; ++num) {
//        cout << remainder * 10 << " / " << D << " = " << quotient << " ... " << remainder * 10 % D << endl;
        vec.push_back(quotient);
        rem[remainder] = num;
        remainder *= 10;
        quotient = remainder / D;
        remainder %= D;
    }
    vec.push_back(quotient);
    start = rem[remainder];
    
    int tmp = vec.at(0), digits = 0;
    while (tmp > 0) {
        tmp /= 10;
        ++digits;
    }
    if (digits == 0)
        ++digits;
    cout << vec.at(0) << ".";
    for (int i = 1; i < start; ++i)
        cout << vec.at(i);
    if (start != vec.size() - 1) {
        cout << "(";
        for (int i = start, size = vec.size(); i < size; ++i) {
            if (i == 75 - digits)
                cout << endl;
            else if (i > 75 - digits && (i - (75 - digits)) % 76 == 0)
                cout << endl;
            cout << vec.at(i);
        }
        cout << ")";
    }
    else if (start == vec.size() - 1 && vec.size() == 2)
        cout << 0;
    cout << endl;
}

void solve(int r, int num) {
    int quotient = r / D, remainder = r % D;
    cout << r << " / " << D << " = " << quotient << " ... " << remainder << endl;
    vec.push_back(quotient);
    if (rem[remainder] == 0) {
        rem[remainder] = num;
        solve(remainder * 10, num + 1);
    }
    else
        start = rem[remainder];
}
