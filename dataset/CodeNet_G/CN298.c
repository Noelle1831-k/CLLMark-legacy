int minWalkers(int N, int* capacities, int* weights) {
    int walkers = N;
    int* lifted = (int*)calloc(N, sizeof(int));
    for (int i = N - 1; i >= 0; --i) {
        if (lifted[i]) continue;
        int currentWeight = weights[i];
        int j = i - 1;
        while (j >= 0 && capacities[j] >= currentWeight) {
            currentWeight += weights[j];
            lifted[j] = 1;
            --j;
        }
        --walkers;
    }
    free(lifted);
    return walkers;
}