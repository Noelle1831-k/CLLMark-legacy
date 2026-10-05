long long countBingoCards(int n, int m, int s, int col, int currSum, int used[], int pos) {
    if (col == n) {
        return (currSum == s) ? 1 : 0;
    }
    long long count = 0;
    for (int i = pos; i <= m; i++) {
        if (!used[i]) {
            used[i] = 1;
            count += countBingoCards(n, m, s, col + (currSum + i) / n, (currSum + i) % n, used, i + 1);
            used[i] = 0;
        }
    }
    return count;
}
int main() {
    int n, m, s;
    while (1) {
        scanf("%d %d %d", &n, &m, &s);
        if (n == 0 && m == 0 && s == 0) break;
        int used[2001] = {0};
        long long result = countBingoCards(n, m, s, 0, 0, used, 1);
        printf("%lld\n", result % 100000);
    }
    return 0;
}