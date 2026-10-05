int main() {
    char file_path[256];
    printf("Welcome to the Data Integrity Analyzer!\n");
    printf("Enter the path to the data file: ");
    scanf("%255s", file_path);
    DataSet *data = load_data(file_path);
    if (!data) {
        log_message("Error: Failed to load data.");
        return EXIT_FAILURE;
    }
    IntegrityResults results;
    results.consistency = check_consistency(data);
    results.accuracy = check_accuracy(data);
    results.completeness = check_completeness(data);
    results.validity = check_validity(data);
    generate_report(&results);
    free_data(data);
    printf("Analysis complete. Report generated.\n");
    return EXIT_SUCCESS;
}