/*
 ID: tony1021
 PROG: combo
 LANG: C++
 */

#include <iostream>
#include <stdio.h>
using namespace std;
int overlap(int[], int[], int);
void Qsort(int [], int, int);

int main() {
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    
    int f[3], m[3], N;
    cin >> N;
    cin >> f[0] >> f[1] >> f[2]
        >> m[0] >> m[1] >> m[2];
    if (N < 5)
        cout << N * N * N << "\n";
    else
        cout << 250 - overlap(f, m, N) << "\n";
    
    
    return 0;
}

int overlap(int f[], int m[], int max) {
    int dial[3][10];
    for (int j = 0; j < 3; ++j)
        for (int i = 0; i < 5; ++i) {
            dial[j][i] = f[j] - 2 + i;
            if (dial[j][i] <= 0)
                dial[j][i] += max;
            else if (dial[j][i] > max)
                dial[j][i] -= max;
            dial[j][9 - i] = m[j] - 2 + i;
            if (dial[j][9 - i] <= 0)
                dial[j][9 - i] += max;
            else if (dial[j][9 - i] > max)
                dial[j][9 - i] -=max;
        // Qsort(dial[j], 0, 10); not appropriate because memory of other rows will be changed when working for the first row
    }
    
    int count[3] = {0, 0, 0};
    for (int k = 0; k < 3; ++k)
    for (int i = 0; i < 10; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            if (dial[k][i] == dial[k][j])
                ++count[k];
        }
    }
    
    return count[0] * count[1] * count[2];
}

void Qsort(int a[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];/*用字表的第一个记录作为枢轴*/
    
    while(first < last)
    {
        while(first < last && a[last] >= key)
        {
            --last;
        }
        
        a[first] = a[last];/*将比第一个小的移到低端*/
        
        while(first < last && a[first] <= key)
        {
            ++first;
        }
        
        a[last] = a[first];
        /*将比第一个大的移到高端*/
    }
    a[first] = key;/*枢轴记录到位*/
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}
