int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int numCommDiv(int x, int y) {
    int count = 0;
    int n = gcd(x, y);
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            count++;
        }
    }
    return count;
}