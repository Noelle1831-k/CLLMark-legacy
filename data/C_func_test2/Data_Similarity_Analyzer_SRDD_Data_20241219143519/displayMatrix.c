void displayMatrix(double **matrix, int size) {
    printf("Similarity Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}