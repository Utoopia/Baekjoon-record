#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

int N;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int apart[25][25] = { 0, };
queue <pair<int, int> > q;
vector <int> v;

void bfs(int a, int b) {
	int cnt = 0;
	pair <int, int> st = { a,b };
	q.push(st);
	cnt++;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ax = x + dx[i];
			int ay = y + dy[i];
			if (ax < 0 || ay < 0 || ax >= N || ay >= N) { continue; }

			if (apart[ax][ay] == 0) { continue; }

			else if (apart[ax][ay] == 1) {
				apart[ax][ay] = apart[x][y] + 1;
				q.push({ ax,ay });
				cnt++;
			}
		}
	}
	v.push_back(cnt);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;
			if (temp == '1') { apart[i][j] = 1; }
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (apart[i][j] == 1) { apart[i][j]++;  bfs(i, j); }
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) { cout << v[i] << endl; }

	return 0;
}