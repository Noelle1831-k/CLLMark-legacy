int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int count_intersections(int x, int y) {
    return x + y - gcd(x, y);
}