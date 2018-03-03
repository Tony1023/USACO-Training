/*
 ID: tony1021
 PROG: pprime
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
int a,b;
void find(int,int);
int quick_pow10(int);
bool isPrime(int);
bool isPal(int,int);

int main() {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    cin >> a >> b;
    int digits = 0, temp = a;
    while (temp > 0) {
        temp /= 10;
        ++digits;
    }
    if (a % 2 == 0)
        ++a;
    while(!isPal(a, digits))
        ++a;
    find(digits, a);
    
    
    return 0;
}

void find(int digits, int num) {
    if (isPrime(num))
        printf("%d\n", num);
    
    //generating the next palindrome number
    bool increased = false, odd = !(digits % 2 == 0);
    int midDig = (digits - 1) / 2; //the unit digit is the 0th, because 10^0 is 1
    for (int i = midDig; !increased && i >= 0; --i) {
        int curDig = (num / quick_pow10(i)) % 10;
        if (curDig == 9) {
            if (i == midDig && odd)
                num -= quick_pow10(i) * 9;
            else {
                num -= quick_pow10(i) * 9;
                num -= quick_pow10(digits - 1 - i) * 9;
            }
        } else {
            increased = true;
            if (i == 0) {
                num += 2;
                if (i != midDig || !odd)
                    num += quick_pow10(digits - 1 - i) * 2;
            } else {
                num += quick_pow10(i);
                if (i != midDig || !odd) {
                    num += quick_pow10(digits - 1 - i);
                }
            }
        }
    }
    if (num <= b) {
        if (increased)
            find(digits, num);
        else
            find(digits + 1, quick_pow10(digits) + 1);
    }
}
bool isPal(int num, int dig) {
    for (int i = 0; i < dig / 2; ++i) {
        int j = (num / quick_pow10(i)) / 10,
        k = (num / quick_pow10(dig - 1 - i)) / 10;
        if (j != k)
            return false;
    }
    return true;
}
bool isPrime(int num) {
//    return true;
    if (num == 0)
        return false;
    for (int i = 3; i < num; i += 2)
        if (num % i == 0)
            return false;
    return true;
}
int quick_pow10(int n) {
    static int pow10[10] = {
            1, 10, 100, 1000, 10000,
            100000, 1000000, 10000000, 100000000, 1000000000
    };
    return pow10[n];
}
