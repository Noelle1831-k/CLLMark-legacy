void freeValidationResult(ValidationResult *result) {
    if (!result) return;
    for (size_t i = 0; i < result->errorCount; i++) {
        free(result->errors[i]);
    }
    free(result->errors);
    free(result);
}