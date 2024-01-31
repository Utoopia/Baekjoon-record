#include <iostream>
#include <cmath>
#define MAX 1000000
using namespace std;

bool primeBool[MAX + 1] = { false, };

int main() {
    int M, N;
    cin >> M >> N;

    for (int i = 2; i < N + 1; i++) {primeBool[i] = true;}

    int len = sqrt(N);

    for (int i = 2; i < len + 1; i++) {      //2부터 n까지의 소수를 판별 후
        if (primeBool[i] == false) { continue; }
            for (int j = i * i; j < N + 1; j += i) {primeBool[j] = false;}
    }

    for (int i = M; i < N + 1; i++) {
        if (primeBool[i] == true) {cout << i << '\n'; }
    }

    return 0;
}