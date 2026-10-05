int calculate_rank(int n, int matches[][4], int results[]) {
    int points[101] = {0};
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        int a = matches[i][0];
        int b = matches[i][1];
        int c = matches[i][2];
        int d = matches[i][3];
        if (c > d) {
            points[a] += 3;
        } else if (c < d) {
            points[b] += 3;
        } else {
            points[a] += 1;
            points[b] += 1;
        }
    }
    int sorted_indices[101];
    for (int i = 1; i <= n; i++) {
        sorted_indices[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (points[sorted_indices[i]] < points[sorted_indices[j]]) {
                int temp = sorted_indices[i];
                sorted_indices[i] = sorted_indices[j];
                sorted_indices[j] = temp;
            }
        }
    }
    int rank = 1;
    for (int i = 1; i <= n; i++) {
        if (i > 1 && points[sorted_indices[i]] < points[sorted_indices[i - 1]]) {
            rank = i;
        }
        results[sorted_indices[i]] = rank;
    }
    return 0;
}