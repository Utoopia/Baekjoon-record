#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 50
using namespace std;

int w, h;
int cnt = 0;
int map[MAX][MAX];
bool visited[MAX][MAX]; 
int dw[8] = { 1, 0, -1, 0 , 1 , 1,-1,-1 };
int dh[8] = { 0, 1, 0 , -1, -1, 1,-1, 1 };

void bfs(int h, int w) {
	queue<pair<int, int>> q;
    q.push(make_pair(h, w));
	visited[h][w] = true;
	
	while(!q.empty()) {
		h = q.front().first;
		w = q.front().second;
		q.pop();
		
		for (int i = 0; i < 8; i++) {
			int nh = h + dh[i];
			int nw = w + dw[i];
			
			if (nh >= 0 && nw >= 0 && nh < MAX && nw < MAX) {
				if (!visited[nh][nw] && map[nh][nw]) {
					visited[nh][nw] = true;
                    q.push(make_pair(nh, nw));
				}							
			}
		}
	}
}

int main() {
	while (1) {
		cin >> w >> h;
		if (!w && !h) break;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] && !visited[i][j]) {
					cnt++;	
					bfs(i, j);
				}
			}
		}
		cout << cnt << "\n";
		memset(map, false, sizeof(map));
		memset(visited, false, sizeof(visited));
		cnt = 0;
	}	
}