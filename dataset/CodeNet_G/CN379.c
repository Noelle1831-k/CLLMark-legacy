int countDudeneyLikeNumbers(int a, int n, int m) {
    int count = 0;
    for (int x = 0; x <= m; x++) {
        int sum = 0;
        int temp = x;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        int y = sum + a;
        long long xn = 1;
        for (int i = 0; i < n; i++) {
            xn *= y;
            if (xn > x) break;
        }
        if (xn == x) {
            count++;
        }
    }
    return count;
}