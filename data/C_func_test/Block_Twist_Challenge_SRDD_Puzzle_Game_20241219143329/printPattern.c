void printPattern(Pattern *pattern) {
    printf("Pattern:\n");
    for (int i = 0; i < pattern->rows; i++) {
        for (int j = 0; j < pattern->cols; j++) {
            printf("%d ", pattern->shape[i][j]);
        }
        printf("\n");
    }
}