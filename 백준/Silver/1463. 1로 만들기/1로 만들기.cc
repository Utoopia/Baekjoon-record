#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int D[1000000];

int main() {
	int N;
	cin >> N;

	D[2] = 1;
	D[3] = 1;

	for (int i = 4; i < N + 1; i++) {
		if (i % 3 == 0 && i % 2 == 0) { D[i] = min({ D[i - 1] + 1, D[i / 3] + 1, D[i / 2] + 1 }); }
		else if (i % 3 == 0) { D[i] = min(D[i - 1] + 1, D[i / 3] + 1); }
		else if (i % 2 == 0) { D[i] = min(D[i - 1] + 1, D[i / 2] + 1); }
		else { D[i] = D[i - 1] + 1; }
	}

	

	cout << D[N];
	
	return 0;
}