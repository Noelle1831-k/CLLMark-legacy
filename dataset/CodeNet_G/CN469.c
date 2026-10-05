#define MAX_N 10
#define MAX_K 4
#define MAX_LENGTH 5
int cards[MAX_N];
int used[MAX_N];
char buffer[MAX_LENGTH * MAX_K];
int buffer_length;
int n, k;
int result_count;
int compare(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}
void generate_permutations(int depth) {
    if (depth == k) {
        buffer[buffer_length] = '\0';
        result_count++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = 1;
            int temp_length = buffer_length;
            buffer_length += sprintf(buffer + buffer_length, "%d", cards[i]);
            generate_permutations(depth + 1);
            buffer_length = temp_length;
            used[i] = 0;
        }
    }
}
int main() {
    while (1) {
        scanf("%d %d", &n, &k);
        if (n == 0 && k == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &cards[i]);
        }
        result_count = 0;
        memset(used, 0, sizeof(used));
        buffer_length = 0;
        generate_permutations(0);
        printf("%d\n", result_count);
    }
    return 0;
}