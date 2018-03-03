/*
 ID: tony1021
 PROG: runround
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
unsigned long M;
bool runsAround(unsigned long);

int main() {
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    cin >> M;
    
    for (unsigned long i = M + 1; i < 987654322; ++i)
        if (runsAround(i)) {
            cout << i << endl;
            break;
        }
    return 0;
}

bool runsAround(unsigned long n) {
    int digits[10], l = 0; //record the digits in an array, although order reversed
    bool digitOccurred[10];
    bool visited[10]; //check if this digit has been visited.
    memset(digitOccurred, false, sizeof(digitOccurred));
    memset(visited, false, sizeof(visited));
    digits[0] = 0;
    while (n > 0) {
        digits[l] = n % 10;
        n /= 10;
        ++l;
    }
    for (int i = 0; i < l; ++i) {
        if (!digitOccurred[digits[i]])
            digitOccurred[digits[i]] = true;
        else
            return false;
    }
    int pos = l - 1;
    for (int run = 0; run < l; ++run) { // run runs [1...n-1]
        visited[pos] = true;
        pos -= digits[pos];
        while (pos < 0)
            pos += l;
    }
    if (pos != l - 1)
        return false;
    for (int i = 0; i < l; ++i)
        if (!visited[i])
            return false;
    return true;
}
