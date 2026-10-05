int sumGp(int a, int n, int r) {
    int sum = 0;
    int curr_term = a;
    for (int i = 0; i < n; i++) {
        sum += curr_term;
        curr_term *= r;
    }
    return sum;
}