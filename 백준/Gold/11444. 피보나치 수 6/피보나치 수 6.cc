#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#define MOD 1000000007
#define endl '\n'
using namespace std;
typedef long long ll;

map<ll, ll> m;

ll fib(ll x) {
    if (m[x]) { return m[x]; }

    ll result;
    if (x % 2 == 0) { result = (fib(x / 2) * (fib(x / 2 + 1) + fib(x / 2 - 1))) % MOD; }
    else { result = ((fib((x + 1) / 2) * fib((x + 1) / 2)) % MOD) + ((fib((x - 1) / 2) * fib((x - 1) / 2)) % MOD) % MOD; }

    return m[x] = result % MOD;
}
int main() {
    m[0] = 0;
    m[1] = 1;
    m[2] = 1;

    ll n;
    cin >> n;
    cout  << fib(n) << endl;
}