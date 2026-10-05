#define MAX_HAMMING 1000000
int is_hamming(int num) {
    if (num < 1) return 0;
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    return num == 1;
}
int count_hamming(int m, int n) {
    int count = 0;
    for (int i = m; i <= n; i++) {
        if (is_hamming(i)) {
            count++;
        }
    }
    return count;
}