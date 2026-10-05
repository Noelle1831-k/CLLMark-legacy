int* calculate_weights(int weight, int* size) {
    static int weights[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    static int result[10];
    int idx = 0;
    for (int i = 9; i >= 0; --i) {
        if (weight >= weights[i]) {
            result[idx++] = weights[i];
            weight -= weights[i];
        }
    }
    *size = idx;
    return result;
}