#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define X first
#define Y second
#define all(v) (v).begin(), (v).end()

using pii = pair<int, int>;
using p = pair<pii, int>;

int ccw(pii a, pii b, pii c) {
	int t = (b.X - a.X) * (c.Y - b.Y) - (c.X - b.X) * (b.Y - a.Y);
	return t ? t > 0 ? 1 : -1 : 0;
}

int dist(pii a, pii b) {
	return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

int main() {
	fastio;
	int N; cin >> N;
	while (N--) {
		int n; cin >> n;
		vector<p> v(n);
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			v[i] = { { a, b }, i };
		}
		swap(v[0], *min_element(all(v)));
		sort(v.begin() + 1, v.end(), [&](p a, p b) {
			if (ccw(v[0].X, a.X, b.X)) return ccw(v[0].X, a.X, b.X) > 0;
			return dist(v[0].X, a.X) < dist(v[0].X, b.X);
		});
		int i = n - 1;
		while (!ccw(v[0].X, v[i - 1].X, v[i].X)) i--;
		reverse(v.begin() + i, v.end());
		for (auto& [a, b] : v) cout << b << ' '; cout << '\n';
	}
}