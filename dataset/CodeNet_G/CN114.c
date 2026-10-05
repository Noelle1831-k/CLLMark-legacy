int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main() {
    int a1, m1, a2, m2, a3, m3;
    while (scanf("%d %d %d %d %d %d", &a1, &m1, &a2, &m2, &a3, &m3) && (a1 || m1 || a2 || m2 || a3 || m3)) {
        if (gcd(a1, m1) != 1 || gcd(a2, m2) != 1 || gcd(a3, m3) != 1) {
            continue;
        }
        int x = 1, y = 1, z = 1;
        int count = 0;
        do {
            x = (x * a1) % m1;
            y = (y * a2) % m2;
            z = (z * a3) % m3;
            count++;
        } while (x != 1 || y != 1 || z != 1);
        printf("%d\n", count);
    }
    return 0;
}