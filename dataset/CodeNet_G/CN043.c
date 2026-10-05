int is_valid_puzzle(int counts[10]) {
    int c, i, j;
    for (i = 1; i <= 9; i++) {
        if (counts[i] >= 2) {
            counts[i] -= 2;
            int triplets = 0;
            for (j = 1; j <= 9; j++) {
                while (counts[j] >= 3) {
                    counts[j] -= 3;
                    triplets++;
                }
            }
            for (j = 1; j <= 7; j++) {
                while (counts[j] >= 1 && counts[j + 1] >= 1 && counts[j + 2] >= 1) {
                    counts[j]--;
                    counts[j + 1]--;
                    counts[j + 2]--;
                    triplets++;
                }
            }
            counts[i] += 2;
            if (triplets >= 4) return 1;
            for (j = 1; j <= 9; j++) {
                while (counts[j] < 0) {
                    if (j <= 7 && counts[j + 1] < 0 && counts[j + 2] < 0) {
                        counts[j]++;
                        counts[j + 1]++;
                        counts[j + 2]++;
                    } else {
                        counts[j] += 3;
                    }
                }
            }
        }
    }
    return 0;
}
void solve_puzzle(const char *digits) {
    int counts[10], original[10], i, possible;
    memset(original, 0, sizeof(original));
    for (i = 0; digits[i]; i++) original[digits[i] - '0']++;
    possible = 0;
    for (i = 1; i <= 9; i++) {
        if (original[i] < 4) {
            memcpy(counts, original, sizeof(counts));
            counts[i]++;
            if (is_valid_puzzle(counts)) {
                if (possible) putchar(' ');
                printf("%d", i);
                possible = 1;
            }
        }
    }
    if (!possible) putchar('0');
    putchar('\n');
}
