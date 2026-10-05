int floorMin(int a, int b, int n) {
    int minValue = (a % n + b % n) % n;
    for (int i = 1; i <= b % n; ++i) {
        int currentValue = (a % n + b % n - i + n) % n;
        if (currentValue < minValue) {
            minValue = currentValue;
        }
    }
    return minValue;
}