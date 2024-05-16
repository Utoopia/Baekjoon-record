#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <bitset>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#define endl '\n'
using namespace std;
typedef long long ll;

struct Point {
    ll x, y;
};

struct passPair {
    int hidx, midx;
};

int ccw(Point& a, Point& b, Point& c) {
    ll sum = a.x * b.y + b.x * c.y + c.x * a.y;
    ll sub = b.x * a.y + c.x * b.y + a.x * c.y;
    if (sum - sub > 0) return 1;
    if (sum - sub < 0) return -1;
    return 0;
}

vector<int> htom[101];
int A[301], B[301];
bool visited[301];

bool dfs(int a) {
    visited[a] = true;
    for (int b : htom[a]) {
        if (B[b] == -1 || (!visited[B[b]] && dfs(B[b]))) {
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

int main() {
        vector<Point> corners;
        vector<Point> holes;
        vector<Point> mice;
        vector<passPair> pp;

        int n, k, h, m;
        cin >> n >> k >> h >> m;

        for (int i = 0; i < n; ++i) {
            Point p;
            cin >> p.x >> p.y;
            corners.push_back(p);
        }

        for (int i = 0; i < h; ++i) {
            Point p;
            cin >> p.x >> p.y;
            holes.push_back(p);
        }

        for (int i = 0; i < m; ++i) {
            Point p;
            cin >> p.x >> p.y;
            mice.push_back(p);
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < m; j++) {
                bool flag = true;
                for (int k = 0; k < n; k++) {
                    if (ccw(corners[k], holes[i], corners[(k + 1) % n]) == 0) continue;
                    if (ccw(corners[k], corners[(k + 1) % n], holes[i]) * ccw(corners[k], corners[(k + 1) % n], mice[j]) > 0) continue;
                    if (ccw(holes[i], mice[j], corners[k]) * ccw(holes[i], mice[j], corners[(k + 1) % n]) > 0) continue;
                    else { flag = false; break; }
                }
                if (flag) { pp.push_back({ i,j }); }
            }
        }

        for (int i = 0; i < 101; ++i) htom[i].clear();
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));

        for (auto i : pp) {
            htom[i.hidx].push_back(i.midx);
        }

        int match = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < k; ++j) {
                memset(visited, false, sizeof(visited));
                if (dfs(i)) match++;
            }
        }

        if (match == m) {
            cout << "Possible" << endl;
        }
        else {
            cout << "Impossible" << endl;
        }
        corners.clear();
        holes.clear();
        pp.clear();
        mice.clear();

    return 0;
}