void create_visualizations(const AnalysisResult result) {
    printf("Creating visualizations...\n");
    printf("Word Frequency Chart:\n");
    for (int i = 0; i < result.word_count; i++) {
        printf("%s: ", result.words[i]);
        for (int j = 0; j < result.frequencies[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}