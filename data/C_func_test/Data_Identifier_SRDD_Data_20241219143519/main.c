int main() {
    char ***data = NULL;
    int rows = 0, cols = 0;
    char **results = NULL;
    char filename[256];
    printf("Enter the dataset file name (CSV format): ");
    scanf("%s", filename);
    load_dataset(filename, &data, &rows, &cols);
    if (rows == 0 || cols == 0) {
        printf("Error: Dataset is empty or invalid.\n");
        return 1;
    }
    results = (char **)malloc(cols * sizeof(char *));
    for (int i = 0; i < cols; i++) {
        results[i] = (char *)malloc(50 * sizeof(char));
    }
    for (int col = 0; col < cols; col++) {
        char **column = (char **)malloc(rows * sizeof(char *));
        for (int row = 0; row < rows; row++) {
            column[row] = data[row][col];
        }
        analyze_column(column, rows, results[col]);
        free(column);
    }
    print_results(results, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);
    for (int i = 0; i < cols; i++) {
        free(results[i]);
    }
    free(results);
    return 0;
}