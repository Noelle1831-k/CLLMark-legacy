#define MAX_N 30000
long long max_sc scones(long long K[], int n, long long m) {
    long long max_scones = 0;
    long long current_scones = 0;
    int start = 0;
    for (int end = 0; end < n; ++end) {
        current_scones += K[end];
        while (current_scones >= m) {
            current_scones -= m;
            if (current_scones > max_scones) {
                max_scones = current_scones;
            }
            current_scones -= K[start];
            start++;
        }
    }
    return max_scones;
}