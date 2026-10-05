int findWeedLength(int n, int heights[]) {
    for (int i = 0; i < n + 1; i++) {
        for (int j = i + 1; j < n + 1; j++) {
            int commonDiff = heights[j] - heights[i];
            int lastValue = heights[i];
            int count = 0;
            for (int k = 0; k < n + 1; k++) {
                if (k == i || k == j) continue;
                if (heights[k] - lastValue == commonDiff) {
                    lastValue = heights[k];
                    count++;
                } else if (heights[k] - lastValue > commonDiff) {
                    break;
                }
            }
            if (count == n - 1) {
                for (int l = 0; l < n + 1; l++) {
                    if (l != i && l != j) continue;
                    if (l == j && count == n - 1) return heights[l];
                    if (l == i) {
                        if (heights[l] - lastValue == commonDiff) {
                            lastValue = heights[l];
                            count++;
                        }
                        if (heights[l] - lastValue > commonDiff) break;
                    }
                }
            }
        }
    }
    return -1;
}