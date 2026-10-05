int main() {
    char dataset1Path[256], dataset2Path[256];
    char exportPath[256];
    char fieldsToMatch[256];
    printf("Welcome to the Data Matcher Application!\n");
    printf("Please follow the instructions to import datasets and match data.\n");
    printf("Enter path for first dataset: ");
    fgets(dataset1Path, sizeof(dataset1Path), stdin);
    trimWhitespace(dataset1Path);
    printf("Enter path for second dataset: ");
    fgets(dataset2Path, sizeof(dataset2Path), stdin);
    trimWhitespace(dataset2Path);
    printf("Enter fields to match (comma-separated): ");
    fgets(fieldsToMatch, sizeof(fieldsToMatch), stdin);
    trimWhitespace(fieldsToMatch);
    printf("Enter path for export file: ");
    fgets(exportPath, sizeof(exportPath), stdin);
    trimWhitespace(exportPath);
    Dataset *dataset1 = loadDataset(dataset1Path);
    Dataset *dataset2 = loadDataset(dataset2Path);
    if (dataset1 == NULL || dataset2 == NULL) {
        fprintf(stderr, "Error: Failed to load datasets. Please check the file paths and try again.\n");
        return EXIT_FAILURE;
    }
    MatchedRecords *matches = matchData(dataset1, dataset2, fieldsToMatch);
    if (matches == NULL || matches->count == 0) {
        printf("No matches found.\n");
    } else {
        generateSummary(matches);
        exportData(matches, exportPath);
    }
    freeDataset(dataset1);
    freeDataset(dataset2);
    freeMatchedRecords(matches);
    printf("Thank you for using the Data Matcher Application!\n");
    return EXIT_SUCCESS;
}