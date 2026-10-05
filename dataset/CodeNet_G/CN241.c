int main() {
    int n;
    while (scanf("%d", &n), n != 0) {
        for (int i = 0; i < n; i++) {
            int x1, y1, z1, w1, x2, y2, z2, w2;
            scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &z1, &w1, &x2, &y2, &z2, &w2);
            int x3 = x1 * x2 - y1 * y2 - z1 * z2 - w1 * w2;
            int y3 = x1 * y2 + y1 * x2 + z1 * w2 - w1 * z2;
            int z3 = x1 * z2 - y1 * w2 + z1 * x2 + w1 * y2;
            int w3 = x1 * w2 + y1 * z2 - z1 * y2 + w1 * x2;
            printf("%d %d %d %d\n", x3, y3, z3, w3);
        }
    }
    return 0;
}