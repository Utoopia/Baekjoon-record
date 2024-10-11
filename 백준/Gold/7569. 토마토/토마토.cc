#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n';
using namespace std;

int M, N, H, days = 0, cnt = 0;
int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };
int box[100][100][100] = { 0, };

struct point{
	int x, y, z;
};

queue <point> q;


// 2차원으로 세로 3행 3층이면
// 3 * 3 으로 총 9까지 가고 가로가 몇 열이든 신경 안써도 됨
// 체크 방법
void bfs() {
	int temp = q.size();
	while (!q.empty()) {
		if (cnt == temp) {
			days++;
			cnt = 0;
			temp = q.size();
		}
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int ax = x + dx[i];
			int ay = y + dy[i];
			int az = z + dz[i];
			if (ax < 0 || ay < 0 || az < 0 || ax >= M || ay >= N || az >= H) { continue; }

			if (box[ax][ay][az] == -1) { continue; }

			if (box[ax][ay][az] == 0) { 
				point pt;
				pt.x = ax;
				pt.y = ay;
				pt.z = az;
				box[ax][ay][az] = 1;	
				q.push(pt); 
			}
		}
		cnt++;
	}
}

bool check_box() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (box[k][j][i] == 0) { return false; }
			}
		}
	}
	return true;
}

int main() {
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				int temp;
				cin >> temp;
				if (temp == 1) {
					point pt;
					pt.z = i;
					pt.y = j;
					pt.x = k;
					q.push(pt);
				}
				box[k][j][i] = temp;
			}
		}
	}

	bool flag = check_box();
	if (flag) { 
		cout << 0 << endl;
		return 0;
	}
	bfs();
	flag = check_box();
	if (flag) { cout << days << endl; }
	else { cout << -1 << endl; }


	return 0;
}