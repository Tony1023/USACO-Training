/*
 ID: tony1021
 PROG: prefix
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
string pfix[201], S;
bool canReach[200002];
int size, maxL = 0, sl;
void search(int);

int main() {
    memset(canReach, false, sizeof(canReach));
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    int i = 0;
    while (cin >> pfix[i] && pfix[i] != ".")
        ++i;
    size = i;
    string s;
    while (cin >> s)
        S += s;
    sl = S.length();
    canReach[0] = true;
    for (int len = 0; len <= sl; ++len) {
        if (canReach[len]) {
            maxL = len;
            int l;
            for (int i = size - 1; i >= 0; --i) {
                l = pfix[i].length();
                if (len + l <= sl && S.compare(len, l, pfix[i]) == 0)
                    canReach[len + l] = true;
            }
        }
    }
    
    cout << maxL << endl;
    
    return 0;
}

void search(int len) {
    if(canReach[len])
        return;
    maxL = max(len, maxL);
    int l;
    for (int i = size - 1; i >= 0; --i) {
        l = pfix[i].length();
        if (len + l <= sl && S.compare(len, l, pfix[i]) == 0)
            search(len + l);
    }
}
