int calculate_minimum_containers(int N, int R, int T, int p[]) {
    int i, j, k;
    int *arrival_time = (int *)malloc(N * sizeof(int));
    int *bottles_needed = (int *)malloc(T * sizeof(int));
    int total_bottles = 0;
    for (i = 0; i < T; i++) {
        bottles_needed[i] = 0;
    }
    for (i = 0; i < N; i++) {
        arrival_time[i] = 0;
    }
    for (j = 0; j <= T; j++) {
        for (i = 0; i < N; i++) {
            if (j > 0 && j % (R / p[i]) == 0) {
                bottles_needed[j] += 1;
                arrival_time[i] = j;
            }
        }
        if (j > 0 && bottles_needed[j - 1] > 0) {
            for (k = j - 1; k >= 0; k--) {
                if (bottles_needed[k] > 0) {
                    bottles_needed[j] += bottles_needed[k];
                    bottles_needed[k] = 0;
                    break;
                }
            }
        }
    }
    for (i = 0; i < T; i++) {
        total_bottles += bottles_needed[i];
    }
    free(arrival_time);
    free(bottles_needed);
    return total_bottles;
}