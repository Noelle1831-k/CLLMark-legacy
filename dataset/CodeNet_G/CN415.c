#define MAX_N 200000
void find_max_point(char *digits, int N, int K, char *result) {
    int stack[MAX_N], top = -1, to_remove = K;
    for (int i = 0; i < N; i++) {
        while (top >= 0 && stack[top] < (digits[i] - '0') && to_remove > 0) {
            top--;
            to_remove--;
        }
        stack[++top] = digits[i] - '0';
    }
    int idx = 0;
    for (int i = 0; i < N - K; i++) {
        result[i] = stack[i] + '0';
    }
    result[N - K] = '\0';
}
