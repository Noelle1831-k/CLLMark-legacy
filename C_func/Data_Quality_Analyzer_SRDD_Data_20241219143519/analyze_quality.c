void analyze_quality(const ValidationResult *result) {
    printf("Data Quality Analysis:\n");
    printf("Consistency: %s\n", result->consistency ? "Pass" : "Fail");
    printf("Accuracy: %s\n", result->accuracy ? "Pass" : "Fail");
    printf("Completeness: %s\n", result->completeness ? "Pass" : "Fail");
    printf("Validity: %s\n", result->validity ? "Pass" : "Fail");
}