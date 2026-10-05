double solve(int n, int k, int m) {
    return (m == 0) ? (1.0 / n) : (1.0 - pow((1.0 - 1.0 / n), k * n));
}
void calculate_probability(int n, int k, int m, int r) {
    double p = solve(n, k, m);
    printf("%.*f\n", r, p);
} 
int main() {
    int n, k, m, r;
    while (1) {
        scanf("%d %d %d %d", &n, &k, &m, &r);
        if (n == 0 && k == 0 && m == 0 && r == 0) break;
        calculate_probability(n, k, m, r);
    }
    return 0;
}