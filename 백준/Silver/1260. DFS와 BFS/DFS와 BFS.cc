#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

bool visited_dfs[1001] = { false, };
bool visited_bfs[1001] = { false, };
bool nodes[1001][1001] = {false,};
queue <int> q;

void dfs(int N, int V) {
	visited_dfs[V] = true;
	cout << V << ' ';
	for (int i = 1; i < N + 1; i++) {
		if (nodes[V][i] && !(visited_dfs[i])) { dfs(N, i); }
	}
}

void bfs(int N, int V) {
	q.push(V);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		visited_bfs[cur] = true;
		cout << cur << ' ';

		for (int i = 1; i < N + 1; i++) {
			if (nodes[cur][i] && !(visited_bfs[i])) { 
				q.push(i); 
				visited_bfs[i] = true;
			}
		}
	}
}

int main() {
	int N, M, V;

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int st, ed;
		cin >> st >> ed;
		nodes[st][ed] = true;
		nodes[ed][st] = true;
	}

	dfs(N, V);
	cout << endl;
	bfs(N, V);

	return 0;
}