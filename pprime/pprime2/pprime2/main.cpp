/*
 ID: tony1021
 PROG: pprime
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int A,B;
int digNum = 0;
void search(int);
bool isPrime(int);

int main() {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    cin >> A >> B;
    int temp = A, tempB = B, B_dig = 0;
    while (temp > 0) {
        ++digNum;
        temp /= 10;
    }
    while (tempB > 0){
        ++B_dig;
        tempB /= 10;
    }
    
    for (int i = digNum; i <= B_dig; ++i)
        search(i);
    
    return 0;
}

void search(int digits) {
    int a = 1, b = 0, c = 0, d = 0, num;
    switch (digits) {
        case 1:
            for (int i = A; i <= 9; i += 2){
                if (num > B)
                    return;
                if (isPrime(i))
                    cout << i << "\n";
            }
            if (B >= 11)
                cout << 11 << "\n";
            return;
        case 3:
            if (digNum == digits) {
                a = A / 100;
                b = (A / 10) % 10;
            }
            for (; a <= 9; a += 2) {
                for (; b <= 9; ++b) {
                    num = a * 100 + b * 10 + a;
                    if (num > B)
                        return;
                    if (isPrime(num))
                        cout << num << "\n";
                }
                b = 0;
            }
            return;
        case 5:
            if (digNum == digits) {
                a = A / 10000;
                b = (A / 1000) % 10;
                c = (A / 100) % 10;
            }
            for (; a <= 9; a += 2) {
                for (; b <= 9; ++b) {
                    for (; c <= 9; ++c) {
                        num = a * 10000 + b * 1000 + c * 100 + b * 10 + a;
                        if (num > B)
                            return;
                        if (isPrime(num))
                            cout << num << "\n";
                    }
                    c = 0;
                }
                b = 0;
            }
            return;
        case 7:
            if (digNum == digits) {
                a = A / 1000000;
                b = (A / 100000) % 10;
                c = (A / 10000) % 10;
                d = (A / 1000) % 10;
            }
            for (; a <= 9; a += 2) {
                for (; b <= 9; ++b) {
                    for (; c <= 9; ++c) {
                        for (; d <= 9; ++d) {
                            num = a * 1000000 + b * 100000 + c * 10000 + d * 1000 + c * 100 + b * 10 + a;
                            if (num > B)
                                return;
                            if (isPrime(num))
                                cout << num << "\n";
                        }
                        d = 0;
                    }
                    c = 0;
                }
                b = 0;
            }
            return;
        default:
            return;
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
