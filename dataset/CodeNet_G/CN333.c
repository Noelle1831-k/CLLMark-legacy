int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int calculate_minimum_cost(int W, int H, int C) {
    int g = gcd(W, H);
    int num_squares = (W / g) * (H / g);
    return num_squares * C;
}