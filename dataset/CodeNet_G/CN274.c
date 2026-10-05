#define MAX_N 10000
int min_challenges(int n, int k[]) {
    int total_remaining = 0;
    int max_individual = 0;
    for (int i = 0; i < n; i++) {
        total_remaining += k[i];
        if (k[i] > 1) {
            max_individual = 1;
        }
    }
    if (max_individual == 0) {
        return -1;
    }
    return total_remaining + 1;
}