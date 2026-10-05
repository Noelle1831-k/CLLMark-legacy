int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <source_code_file>\n", argv[0]);
        return 1;
    }
    char *sourceCode = readFile(argv[1]);
    if (sourceCode == NULL) {
        printf("Error reading file: %s\n", argv[1]);
        return 1;
    }
    AnalysisResult *result = analyzeCode(sourceCode);
    if (result == NULL) {
        printf("Error analyzing code.\n");
        free(sourceCode);
        return 1;
    }
    generateReport(result);
    freeAnalysisResult(result);
    free(sourceCode);
    return 0;
}