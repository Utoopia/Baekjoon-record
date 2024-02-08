#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#define endl '\n'
using namespace std;

vector <long long> v;

int main() {
	int N;
	cin >> N;
	

	for (int i = 0; i < N; i++) {
		long long temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	sort(v.begin(), v.end());

	long long output = 0;

	for (int i = 0; i < N; i++) {
		output += abs(i + 1 - v[i]);
	}

	cout << output;

	return 0;
}