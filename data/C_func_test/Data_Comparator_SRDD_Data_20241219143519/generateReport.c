void generateReport(ComparisonResult *result) {
    printf("Comparison Report:\n");
    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
            if (result->discrepancies[i][j]) {
                printf("Discrepancy at row %d, column %d\n", i, j);
            }
        }
    }
}