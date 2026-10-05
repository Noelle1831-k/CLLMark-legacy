#define MAX_N 10000
#define INF 1000000000
int N, cut_cost[MAX_N];
int dp[MAX_N][MAX_N];
int min(int a, int b) {
    return a < b ? a : b;
}
int solve(int left, int right) {
    if (right - left == N / 2) return 0;
    if (dp[left][right] != -1) return dp[left][right];
    int res = INF;
    for (int cut = 1; cut < N; ++cut) {
        if ((cut <= left || cut >= right) && abs(left - right + 1) <= N / 2) {
            res = min(res, solve(left, cut) + solve(cut, right) + cut_cost[cut]);
        }
    }
    dp[left][right] = res;
    return res;
}
int main() {
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            dp[i][j] = -1;
        }
    }
}