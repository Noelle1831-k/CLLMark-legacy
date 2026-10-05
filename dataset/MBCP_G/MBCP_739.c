int findIndex(int n) {
    long long lower = pow(10, n-1);
    long long upper = pow(10, n) - 1;
    int index = ceil((-1 + sqrt(1 + 8 * lower)) / 2);
    while (1) {
        long long t = index * (index + 1) / 2;
        if (t >= lower && t <= upper) {
            return index;
        }
        index++;
    }
}