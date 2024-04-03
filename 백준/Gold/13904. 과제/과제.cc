#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int cost[1002];

bool cmp(pair<int, int>& v1, pair<int, int>& v2) {

	if (v1.second == v2.first) {
		return v1.first < v1.first;
	}
	else return v1.second > v2.second;
}

int main() {

	int  n; cin >> n;

	vector <pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;

	}
	sort(v.begin(), v.end(), cmp);

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = v[i].first; j > 0; j--) {
			if (!cost[j]) {
				cost[j] = v[i].second;
				res += v[i].second;
				break;
			}
		}
	}
	cout << res;
}
