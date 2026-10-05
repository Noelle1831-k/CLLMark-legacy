int abs_diff(int a, int b) {
    int diff = a - b;
    return diff < 0 ? -diff : diff;
}
int calculate_energy(int bm, int bw) {
    int diff = abs_diff(bm, bw);
    return diff * (diff - 30) * (diff - 30);
}
int max_energy(int M, int W, int *bm, int *bw) {
    int max_energy = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < W; ++j) {
            int energy = calculate_energy(bm[i], bw[j]);
            if (energy > max_energy) {
                max_energy = energy;
            }
        }
    }
    return max_energy;
}