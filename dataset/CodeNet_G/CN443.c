#define MAX_N 100
typedef struct {
    int p, q, r, b;
    int total_weight;
} Bar;
Bar bars[MAX_N + 1];
int n;
int calculate_weight(int index) {
    if (bars[index].total_weight >= 0) return bars[index].total_weight;
    int r_weight = (bars[index].r == 0) ? 1 : calculate_weight(bars[index].r);
    int b_weight = (bars[index].b == 0) ? 1 : calculate_weight(bars[index].b);
    int total_weight = bars[index].q * r_weight + bars[index].p * b_weight;
    bars[index].total_weight = total_weight;
    return total_weight;
}
int solve() {
    for (int i = 1; i <= n; i++) bars[i].total_weight = -1;
    int total_weight = 0;
    for (int i = 1; i <= n; i++) if (bars[i].total_weight < 0) total_weight += calculate_weight(i);
    return total_weight;
}
void input() {
    int p, q, r, b;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &p, &q, &r, &b);
        bars[i].p = p;
        bars[i].q = q;
        bars[i].r = r;
        bars[i].b = b;
    }
}
int main() {
    while (scanf("%d", &n), n) {
        input();
        printf("%d\n", solve());
    }
    return 0;
}