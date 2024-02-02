#include <iostream>
using namespace std;
int t[504][504] = { 0 }; // 정수 삼각형 입력 받을 배열
int dp[504][504] = { 0 }; // 최대 합을 저장할 배열
int result = -1;
int mx(int a, int b) { // 두 수 중 큰 값을 반환하는 함수
    if (a > b)
        return a;
    else
        return b;
}
int main() {
    int n;
    cin >> n;
    int idx = 1;
    for (int i = 1; i <= n; i++) { // 정수 삼각형 입력 받음
        for (int j = 1; j <= i; j++) {
            cin >> t[i][j];
        }
    }
    dp[1][1] = t[1][1]; // 맨 꼭대기 층은 같음
    for (int i = 2; i <= n; i++) { // 2번째 줄 부터 시작
        for (int j = 1; j <= i; j++) { // 1번째 칸 부터 시작
            dp[i][j] = mx(dp[i - 1][j - 1], dp[i - 1][j]) + t[i][j];
            // 윗 줄 중 바로 위쪽, 왼쪽 대각선 중 큰 것을 골라
            // 자기 칸의 값과 더함.
        }
    }
    for (int i = 1; i <= n; i++) { // 마지막 줄 중 가장 큰 것을 고름
        if (result < dp[n][i])
            result = dp[n][i];
    }
    cout << result; // 결과 출력
    return 0;
}