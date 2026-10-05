void free_validation_result(ValidationResult *result) {
    if (result) {
        free(result);
    }
}