void freeComparisonResult(ComparisonResult *result) {
    if (result != NULL) {
        free2DArray(result->discrepancies, result->rows);
        free(result);
    }
}