#define MAX_SIZE 100
void process_table() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        int data[MAX_SIZE][MAX_SIZE];
        int row_sum[MAX_SIZE] = {0};
        int col_sum[MAX_SIZE] = {0};
        int grand_total = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &data[i][j]);
                row_sum[i] += data[i][j];
                col_sum[j] += data[i][j];
                grand_total += data[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%5d", data[i][j]);
            }
            printf("%5d\n", row_sum[i]);
        }
        for (int j = 0; j < n; ++j) {
            printf("%5d", col_sum[j]);
        }
        printf("%5d\n", grand_total);
    }
}