/*
  ID: tony1021
  PROG: humble
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int K, N;
int oSet[100];
int pindex[100];
long long hNums[100001];

int main() {
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);
	memset(pindex, 0, sizeof(pindex));
	cin >> K >> N;
	for (int i = 0; i < K; ++i) {
		cin >> oSet[i];
	}
	hNums[0] = 1;
	for (int i = 0; i <= N; ++i) {
		long long nexthNum = hNums[i] * oSet[K - 1]; //starting with the largest hnum
		//search in increaments
		for (int curoSet = 0; curoSet < K; ++curoSet) {
			for (int curhNum = pindex[curoSet]; curhNum <= i; ++curhNum) {
				if (oSet[curoSet] * hNums[curhNum] > hNums[i]) {
					nexthNum = min(nexthNum, oSet[curoSet] * hNums[curhNum]);
					pindex[curoSet] = curhNum;
					break;
				}
			}
		}
		hNums[i + 1] = nexthNum;
	}
	cout << hNums[N] << endl;
	return 0;
}