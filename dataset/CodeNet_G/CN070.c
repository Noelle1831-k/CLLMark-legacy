int countCombinations(int n, int s, int usedMask) {
    if (n == 0) return s == 0;
    int count = 0;
    for (int i = 0; i <= 9; i++) {
        if (!(usedMask & (1 << i))) {
            count += countCombinations(n - 1, s - i * n, usedMask | (1 << i));
        }
    }
    return count;
}
int main() {
    int n, s;
    while (scanf("%d %d", &n, &s) == 2) {
        printf("%d\n", countCombinations(n, s, 0));
    }
    return 0;
}
