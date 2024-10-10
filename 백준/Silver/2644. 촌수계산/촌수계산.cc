#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define endl '\n'
using namespace std;

int n, st, ed, m, cnt = 0, result = 0;
bool famliy[101][101] = { false, };
bool visited[101] = {false,};

void dfs(int cur, int num) {
	visited[cur] = true;

	if (cur == ed) { result = num; }

	for (int i = 1; i < n + 1; i++) {
		if (famliy[cur][i] && !visited[i]) { 
			cnt++;
			dfs(i, num + 1);
		}
	}

}

int main() {
	cin >> n >> st >> ed;

	cin >> m;

	for (int i = 0; i < m; i++) {
		int tempx, tempy;
		cin >> tempx >> tempy;
		famliy[tempx][tempy] = true;
		famliy[tempy][tempx] = true;
	}
	
	dfs(st, 0);

	if (result == 0) { cout << -1 << endl; }
	else { cout << result << endl; }

	return 0;
}