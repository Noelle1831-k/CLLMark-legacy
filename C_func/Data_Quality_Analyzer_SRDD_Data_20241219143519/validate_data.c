ValidationResult* validate_data(const DataSet *data_set) {
    ValidationResult *result = (ValidationResult *)malloc(sizeof(ValidationResult));
    if (!result) {
        perror("Error allocating memory for validation result");
        return NULL;
    }
    result->consistency = check_consistency(data_set);
    result->accuracy = check_accuracy(data_set);
    result->completeness = check_completeness(data_set);
    result->validity = check_validity(data_set);
    return result;
}