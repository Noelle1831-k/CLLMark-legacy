int main() {
    char filePath[MAX_FILE_PATH];
    int variableIndex;
    Dataset dataset;
    printWelcomeMessage();
    handleUserInput(filePath, &variableIndex);
    dataset = importData(filePath);
    if (dataset.size == 0) {
        printf("Error: Dataset loading failed. Exiting program.\n");
        return 1;
    }
    if (variableIndex < 1 || variableIndex > dataset.numColumns) {
        printf("Error: Invalid variable index. Exiting program.\n");
        freeDataset(&dataset);
        return 1;
    }
    FrequencyTable table = calculateFrequencies(&dataset, variableIndex - 1);
    displayFrequencyTable(&table);
    printf("\nGenerating histogram...\n");
    generateHistogram(&table);
    freeFrequencyTable(&table);
    freeDataset(&dataset);
    printf("\nAnalysis complete. Thank you for using the Data Frequency Analyzer.\n");
    return 0;
}