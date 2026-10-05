#define MAX_M 1000
#define MAX_N 1000
char grid[MAX_M + 1][MAX_N + 1];
int sumJ[MAX_M + 1][MAX_N + 1];
int sumO[MAX_M + 1][MAX_N + 1];
int sumI[MAX_M + 1][MAX_N + 1];
void processInput(int M, int N) {
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            sumJ[i][j] = sumJ[i - 1][j] + sumJ[i][j - 1] - sumJ[i - 1][j - 1];
            sumO[i][j] = sumO[i - 1][j] + sumO[i][j - 1] - sumO[i - 1][j - 1];
            sumI[i][j] = sumI[i - 1][j] + sumI[i][j - 1] - sumI[i - 1][j - 1];
            if (grid[i][j] == 'J') sumJ[i][j]++;
            else if (grid[i][j] == 'O') sumO[i][j]++;
            else if (grid[i][j] == 'I') sumI[i][j]++;
        }
    }
}
void queryRegion(int aj, int bj, int cj, int dj, int* resultJ, int* resultO, int* resultI) {
    *resultJ = sumJ[cj][dj] - sumJ[aj - 1][dj] - sumJ[cj][bj - 1] + sumJ[aj - 1][bj - 1];
    *resultO = sumO[cj][dj] - sumO[aj - 1][dj] - sumO[cj][bj - 1] + sumO[aj - 1][bj - 1];
    *resultI = sumI[cj][dj] - sumI[aj - 1][dj] - sumI[cj][bj - 1] + sumI[aj - 1][bj - 1];
}