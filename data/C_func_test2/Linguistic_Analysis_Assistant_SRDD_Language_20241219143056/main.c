int main() {
    printf("Initializing Text Analysis Software...\n");
    TextAnalyzer *analyzer = createTextAnalyzer();
    printf("Loading text from file...\n");
    loadText(analyzer, "input.txt");
    printf("Analyzing text...\n");
    analyze(analyzer);
    printf("Cleaning up resources...\n");
    destroyTextAnalyzer(analyzer);
    printf("Text analysis completed successfully.\n");
    return 0;
}