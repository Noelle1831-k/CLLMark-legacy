int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <data_file>\n", argv[0]);
        return 1;
    }
    DataSet *data = load_data(argv[1]);
    if (data == NULL) {
        printf("Error: Unable to load data from file %s\n", argv[1]);
        return 1;
    }
    printf("Data Summary:\n");
    profile_data(data);
    printf("\nDetecting missing values...\n");
    check_missing_values(data);
    printf("\nDetecting outliers using Z-score...\n");
    detect_outliers_zscore(data);
    printf("\nHistogram for the first column:\n");
    print_histogram(data, 0);
    free_data(data);
    return 0;
}