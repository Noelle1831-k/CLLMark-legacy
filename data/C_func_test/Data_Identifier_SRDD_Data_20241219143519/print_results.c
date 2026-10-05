void print_results(char **results, int cols) {
    printf("\nData Types Detected:\n");
    for (int i = 0; i < cols; i++) {
        printf("Column %d: %s\n", i + 1, results[i]);
    }
}