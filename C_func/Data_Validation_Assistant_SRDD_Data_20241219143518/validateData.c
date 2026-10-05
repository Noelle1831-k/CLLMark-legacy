ValidationResult* validateData(DataSet *dataSet, ValidationRules *rules) {
    ValidationResult *result = (ValidationResult *)malloc(sizeof(ValidationResult));
    if (!result) {
        fprintf(stderr, "Memory allocation failed for ValidationResult.\n");
        return NULL;
    }
    result->errors = (char **)malloc(100 * sizeof(char *));
    if (!result->errors) {
        fprintf(stderr, "Memory allocation failed for error messages.\n");
        free(result);
        return NULL;
    }
    result->errorCount = 0;
    for (size_t i = 0; i < dataSet->size; i++) {
        char *entry = dataSet->data[i];
        if (rules->typeValidation && !isValidType(entry)) {
            result->errors[result->errorCount++] = strdup("Type validation failed.");
        }
        if (rules->rangeValidation && !isInRange(entry, rules->minRange, rules->maxRange)) {
            result->errors[result->errorCount++] = strdup("Range validation failed.");
        }
        if (rules->uniquenessValidation && !isUnique(entry, dataSet, i)) {
            result->errors[result->errorCount++] = strdup("Uniqueness validation failed.");
        }
    }
    return result;
}