int count_combinations(int n, int s, int start, int current_sum) {
    if (n == 0) {
        return current_sum == s ? 1 : 0;
    }
    if (start > 100 || current_sum > s) {
        return 0;
    }
    int count = 0;
    for (int i = start; i <= 100; i++) {
        count += count_combinations(n - 1, s, i + 1, current_sum + i);
    }
    return count;
}
int main() {
    int n, s;
    while (scanf("%d %d", &n, &s), n || s) {
        printf("%d\n", count_combinations(n, s, 0, 0));
    }
    return 0;
}
