#include <iostream>
#include <cmath>

using namespace std;

int N, i, j;
int result = 0;

void divide(int x, int y, int n) {

    if (x == i && y == j) {
        cout << result;
        exit(0);
    }

    if (!(i < x + n && j < y + n)) {
        
        result += n * n;
        return;
    }
   
    divide(x, y, n / 2); 
    divide(x, y + n / 2, n / 2);
    divide(x + n / 2, y, n / 2);
    divide(x + n / 2, y + n / 2, n / 2);
}

int main() {

    cin >> N;
    cin >> i >> j;

    divide(0, 0, pow(2, N));
    return 0;
}
