/*
 ID: tony1021
 PROG: sprime
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int N, num[6] = {1,2,3,5,7,9}, digits[8];
void solve(int, int);
bool isPrime(int);

int main() {
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    cin >> N;
    solve(0, 0);
    
    return 0;
}

void solve(int n, int curNum) {
    if (n == N)
        cout << curNum << endl;
    int nextNum;
    for (int i = 0; i < 6; ++i) { //appending numbers to the original number
        if ((n != 0 && num[i] == 2) || (n == 0 && num[i] == 1))
            continue;
        nextNum = curNum * 10 + num[i];
        if (isPrime(nextNum))
            solve(n+1, nextNum);
    }
}

bool isPrime(int num) {
    double half = sqrt(num) + 1;
    for (int i = 3; i < half; i += 2) {
        if (num % i == 0)
            return false;
    }
    return true;
}
