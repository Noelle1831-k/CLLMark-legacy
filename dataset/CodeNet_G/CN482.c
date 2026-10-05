#define MOD 100000
int M, N;
char flag[20][21];
int dp[20][20][512];
int isGood(int mask, int i, int j) {
    return (mask & (1 << (i * N + j))) && 
           (mask & (1 << (i * N + j + 1))) &&
           (mask & (1 << ((i + 1) * N + j)));
}
int main() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++) {
        scanf("%s", flag[i]);
    }
    int totalPositions = M * N;
    int fullMask = 1 << totalPositions;
    dp[0][0][0] = 1;
    for (int mask = 0; mask < fullMask; mask++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if ((mask & (1 << (i * N + j))) || flag[i][j] != '?') {
                    int nextMask = mask;
                    if (flag[i][j] == '?' || flag[i][j] == 'J') 
                        nextMask |= 1 << (i * N + j);
                    int ii = i, jj = j + 1;
                    if (jj == N) { jj = 0; ii++; }
                    if (ii < M) dp[ii][jj][nextMask] = (dp[ii][jj][nextMask] + dp[i][j][mask]) % MOD;
                    continue;
                }
                for (int k = 0; k < 3; k++) {
                    int nextMask = mask | (1 << (i * N + j));
                    if (k == 0 && 'J' != flag[i][j]) continue;
                    if (k == 1 && 'O' != flag[i][j]) continue;
                    if (k == 2 && 'I' != flag[i][j]) continue;
                    int ii = i, jj = j + 1;
                    if (jj == N) { jj = 0; ii++; }
                    if (ii < M) dp[ii][jj][nextMask] = (dp[ii][jj][nextMask] + dp[i][j][mask]) % MOD;
                }
            }
        }
    }
    int count = 0;
    for (int mask = 0; mask < fullMask; mask++) {
        int goodFlag = 0;
        for (int i = 0; i < M - 1 && !goodFlag; i++) {
            for (int j = 0; j < N - 1 && !goodFlag; j++) {
                if (isGood(mask, i, j)) goodFlag = 1;
            }
        }
        if (goodFlag) count = (count + dp[M - 1][N - 1][mask]) % MOD;
    }
    printf("%d\n", count);
    return 0;
}
