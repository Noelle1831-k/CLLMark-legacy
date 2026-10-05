int main() {
    int prices[] = {6000, 4000, 3000, 2000};
    for (int i = 0; i < 4; i++) {
        int t, n;
        scanf("%d %d", &t, &n);
        printf("%d\n", prices[t - 1] * n);
    }
    return 0;
}