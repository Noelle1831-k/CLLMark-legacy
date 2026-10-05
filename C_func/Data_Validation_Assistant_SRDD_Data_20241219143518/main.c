int main() {
    printf("Welcome to the Data Validation Assistant!\n");
    char *filePath = (char *)malloc(256 * sizeof(char));
    if (!filePath) {
        fprintf(stderr, "Memory allocation failed for file path.\n");
        return 1;
    }
    printf("Enter the path to your dataset: ");
    if (scanf("%255s", filePath) != 1) {
        fprintf(stderr, "Failed to read file path.\n");
        free(filePath);
        return 1;
    }
    DataSet *dataSet = importData(filePath);
    if (dataSet == NULL) {
        printf("Failed to import data.\n");
        free(filePath);
        return 1;
    }
    ValidationRules *rules = createValidationRules();
    if (!rules) {
        fprintf(stderr, "Failed to create validation rules.\n");
        freeDataSet(dataSet);
        free(filePath);
        return 1;
    }
    applyValidationRules(dataSet, rules);
    ValidationResult *result = validateData(dataSet, rules);
    if (!result) {
        fprintf(stderr, "Validation failed.\n");
        freeDataSet(dataSet);
        freeValidationRules(rules);
        free(filePath);
        return 1;
    }
    generateReport(result);
    freeDataSet(dataSet);
    freeValidationRules(rules);
    freeValidationResult(result);
    free(filePath);
    printf("Validation complete. Report generated.\n");
    return 0;
}