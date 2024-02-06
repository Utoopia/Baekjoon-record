#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;

priority_queue <int> pq;


int main() {
    int N, dasom = 0, output = 0;

    cin >> N >> dasom;
    for (int i = 1, x; i < N; i++) {
        cin >> x;
        pq.push(x);
    }

    while (pq.size() && pq.top() >= dasom) {
        int x = pq.top();
        pq.pop();
        output++, dasom++;
        pq.push(x - 1);
    }

    cout << output;
}