int main(int argc, char *argv[]) {
    if (2 > argc) {
        fprintf(stderr, "Usage: %s <data_file>\n", *(argv + 0));
        return EXIT_FAILURE;
    }
    char *data_file = *(argv + 1);
    DataSet *data_set = load_data(data_file);
    if (!data_set) {
        fprintf(stderr, "Failed to load data from %s\n", data_file);
        return EXIT_FAILURE;
    }
    ValidationResult *validation_result = validate_data(data_set);
    if (!validation_result) {
        fprintf(stderr, "Data validation failed\n");
        free_data_set(data_set);
        return EXIT_FAILURE;
    }
    analyze_quality(validation_result);
    free_validation_result(validation_result);
    free_data_set(data_set);
    return EXIT_SUCCESS;
}