void findWinners(int n, int a[], int v[], int *winner, int *maxFish) {
    *maxFish = -1;
    for (int i = 0; i < n; ++i) {
        if (v[i] > *maxFish || (v[i] == *maxFish && a[i] < *winner)) {
            *maxFish = v[i];
            *winner = a[i];
        }
    }
}