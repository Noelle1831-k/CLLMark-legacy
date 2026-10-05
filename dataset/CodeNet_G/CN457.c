#define MAXN 10000
int remainingCharacters(int N, int colors[MAXN]) {
    int minRemaining = N;
    for (int i = 0; i < N; i++) {
        int originalColor = colors[i];
        for (int newColor = 1; newColor <= 3; newColor++) {
            if (newColor == originalColor) continue;
            colors[i] = newColor;
            int count[MAXN] = {0}, R = 0;
            for (int j = 0; j < N; j++) {
                if (j == 0 || colors[j] != colors[j - 1]) {
                    count[R++] = 1;
                } else {
                    count[R - 1]++;
                }
            }
            int total = N;
            for (int j = 0; j < R;) {
                if (count[j] >= 4) {
                    total -= count[j];
                    int k = j + 1;
                    while (k < R && colors[k-1] == colors[k]) {
                        count[j] += count[k];
                        total -= count[k];
                        k++;
                    }
                    j = k;
                } else {
                    j++;
                }
            }
            if (total < minRemaining) minRemaining = total;
            colors[i] = originalColor;
        }
    }
    return minRemaining;
}