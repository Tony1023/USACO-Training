/*
  ID: tony1021
  PROG: contact
  LANG: C++
  */

#include <iostream>
#include <cstring>
#include <fstream>
#include <limits>
#include <algorithm>
using namespace std;

int A, B, N, L;
int occ[9000];
int pow2[14] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};
string sig = "";

int main() {
	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);
	memset(occ, 0, sizeof(occ));
	cin >> A >> B >> N;
	string temp;
	while (cin >> temp)
		sig += temp;
	//cout << sig;
	L = sig.size();

	// Reversing the searching order
	for (int start = L - 1; start >= A - 1; --start) {
		int index = 0;
		for (int len = 1; len <= B && start - len >= -1; ++len) {
			if (sig[start - len + 1] == '1')
				index += pow2[len - 1];
			++occ[index + pow2[len]];
		}
	}

	int outputed = 0;
	while (outputed < N) {
		int mf = 0;
		// Finding the maximum frequency for now
		for (int i = pow2[A]; i < pow2[B + 1]; ++i)
			mf = max(mf, occ[i]);
		if (mf == 0)
			return 0;
		// cout the maximums. 
		cout << mf << '\n';
		int count = 0;
		for (int i = pow2[A]; i < pow2[B + 1] && outputed < N; ++i) {
			if (occ[i] == mf) {
				// Printing a space or an enter
				if (count > 0) {
					if (count % 6 != 0)
						cout << " ";
					else
						cout << '\n';
				}
				int j = i, k = B + 1;
				while (pow2[k] > j)
					--k;
				j -= pow2[k--];
				for (; k >= 0; --k) {
					if (pow2[k] <= j) {
						cout << '1';
						j -= pow2[k];
					}
					else
						cout << '0';
				}
				occ[i] = -occ[i];
				++count;
			}
		}
		++outputed;
		cout << endl;
	}
	return 0;
}