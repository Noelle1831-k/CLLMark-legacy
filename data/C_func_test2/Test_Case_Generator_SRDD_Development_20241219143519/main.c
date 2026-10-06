int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter code snippet or function signature:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    ParsedData *parsedData = parseInput(input);
    if (parsedData == NULL) {
        fprintf(stderr, "Error parsing input.\n");
        return EXIT_FAILURE;
    }
    TestCase *testCases = generateTestCases(parsedData);
    if (testCases == NULL) {
        fprintf(stderr, "Error generating test cases.\n");
        freeParsedData(parsedData);
        return EXIT_FAILURE;
    }
    int exportChoice;
    printf("Choose export format (1 for JSON, 2 for CSV): ");
    scanf("%d", &exportChoice);
    if (exportChoice == 1) {
        exportToJSON(testCases);
    } else if (exportChoice == 2) {
        exportToCSV(testCases);
    } else {
        fprintf(stderr, "Invalid choice.\n");
    }
    freeTestCases(testCases);
    freeParsedData(parsedData);
    return EXIT_SUCCESS;
}