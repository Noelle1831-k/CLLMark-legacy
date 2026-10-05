double calculate_minimum_height(int N, int t, int x[], int h[]) {
    double min_height = 0.0;
    for (int i = 0; i < N; ++i) {
        double height = ((double)h[i] * (t - 1)) / (t - x[i] - 1);
        if (height > min_height) {
            min_height = height;
        }
    }
    return min_height;
}
