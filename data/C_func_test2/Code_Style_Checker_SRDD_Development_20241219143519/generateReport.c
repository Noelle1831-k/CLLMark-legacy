void generateReport(const AnalysisResult *result) {
    printf("Code Style Analysis Report:\n");
    printf("-----------------------------------\n");
    printf("Indentation Issues: %d\n", result->indentationIssues);
    printf("Unused Variables: %d\n", result->unusedVariables);
    printf("Naming Convention Violations: %d\n", result->namingConventions);
    printf("Missing Comments: %d\n", result->missingComments);
    printf("-----------------------------------\n");
    printf("Suggestions:\n");
    if (result->indentationIssues > 0) {
        printf("- Fix inconsistent indentation.\n");
    }
    if (result->unusedVariables > 0) {
        printf("- Remove or use declared variables that are not used.\n");
    }
    if (result->namingConventions > 0) {
        printf("- Use camelCase for variables and PascalCase for types.\n");
    }
    if (result->missingComments > 0) {
        printf("- Add comments to improve code readability.\n");
    }
}