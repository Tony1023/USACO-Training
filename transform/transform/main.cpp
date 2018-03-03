/*
 ID: tony1021
 PROG: transform
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#define MAX 10
#define For(i,n) for (int i = 0; i < n; ++i)

int transform(char [MAX][MAX], char [MAX][MAX], bool, int);
bool same(char [MAX][MAX], char [MAX][MAX], int);

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    
    char square[MAX][MAX], target[MAX][MAX];
    int N;
    cin >> N;
    For(i, N)
        scanf("%s", square[i]);
    For(i, N)
        scanf("%s", target[i]);
    
    cout << transform(square, target, false, N) << endl;
    
    return 0;
}

bool same(char s[MAX][MAX], char t[MAX][MAX], int size){
    For(i, size)
        For(j, size)
            if (s[i][j] != t[i][j])
                return false;
    return true;
}

int transform(char s[MAX][MAX], char t[MAX][MAX], bool reflected, int size) {
    
    for (int k = 1; k <= 7; ++k) {
        char copy[MAX][MAX];
        switch (k) {
            case 1:  //rotate 90deg
                For(i, size)
                    For(j, size)
                        copy[i][j] = s[size - j - 1][i];
                break;
            case 2:  //rotate 180deg
                For(i, size)
                    For(j, size)
                        copy[i][j] = s[size - i - 1][size - j - 1];
                break;
            case 3:  //rotate 270deg
                For(i, size)
                    For(j, size)
                        copy[i][j] = s[j][size - i - 1];
                break;
            case 4:  //reflect horizontally
                For(i, size)
                    For(j, size)
                        copy[i][j] = s[i][size - j - 1];
                break;
            case 5:  //Check combination
                if (reflected) //if it has been reflected then return 7
                    return 7;
                //First reflect then rotate, using recurrence
                For(i, size)
                    For(j, size)
                        copy[i][j] = s[i][size - j - 1];
                if (transform(copy, t, true, size) <= 4)
                    return 5;
            case 6:  //simply copy the originall square
                For(i, size)
                    For(j, size)
                        copy[i][j] = s[i][j];
                break;
            case 7:  //cannot be obtained by these transformation
                return 7;
        }
        if (same(copy, t, size))
            return k;
    }
    return 0;
}














