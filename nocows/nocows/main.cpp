/*
 ID: tony1021
 PROG: nocows
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int N, nK, K, pt[201][100][2];
int partitions(int,int);
void computePower();

int main() {
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    cin >> N >> nK;
    K = nK;
    //Check if the nodes are too few and if the nodes are odd numbers
    if (N + 1 < K * 2 || N % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    memset(pt, -1, sizeof(pt));
    int total = 0, num;
    bool plus = true;
    do {
        num = partitions(N - 1, 1);
        if (plus)
            total += num;
        else {
            total -= num;
            break;
        }
        plus = !plus;
        --K;
        
    } while (num != 0);
    total %= 9901;
    if (total < 0)
        total += 9901;
    cout << total << endl;
    return 0;
}

int partitions(int nodesLeft, int ht) { //determine the number of partitions under this node, given the height and nodesLeft
    if (ht == K - 1) {
        if (nodesLeft == 2)
            return 1;
        if (nodesLeft > 2) //nodes are not exhausted, thus this partition does not work
            return 0;
    }
    if (nodesLeft == 0)
        return 1;
    
    int total = 0;
    nodesLeft -= 2; //subtracting the nodes in this layer
    if (pt[nodesLeft][ht][nK - K] != -1)
        return pt[nodesLeft][ht][nK - K];
    for (int i = 0; i <= nodesLeft; i += 2) {
        int left = partitions(i, ht + 1), right = partitions(nodesLeft - i, ht + 1);
        total += (left * right);
    }
    return pt[nodesLeft][ht][nK - K] = total % 9901;
}

/*
Notes:
Remember to check all the input possibilities, and never make assumptions that are unstated in the question.
When taking modulus, although all the result of all operations remain the same, remember to ensure that the numbers in each step are inside bounds. 
Make sure the final result should be positive: 1001 - 999 = 2, but 1001%1000 - 999 % 1000 = -998. Add the modulus number to the result to correct the mistake. -998 + 1000 = 2.
*/
