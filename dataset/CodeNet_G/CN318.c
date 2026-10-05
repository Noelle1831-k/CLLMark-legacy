double calculateMaximumDistance(int N, int x[], int r[]) {
    double low = 0.0, high = 1000000.0, mid;
    while (high - low > 0.000001) {
        mid = (low + high) / 2.0;
        double left_bound = -1e9, right_bound = 1e9;
        for (int i = 0; i < N; ++i) {
            double limit = sqrt((r[i] - mid) * (r[i] - mid) - mid * mid);
            left_bound = fmax(left_bound, x[i] - limit);
            right_bound = fmin(right_bound, x[i] + limit);
        }
        if (left_bound <= right_bound) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}