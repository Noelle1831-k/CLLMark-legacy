void generate_recommendations(SleepAnalyzer *analyzer) {
    for (int i = 0; analyzer->count > i; i++) {
        printf("Generating recommendations for date: %s\n", analyzer->data[i].date);
    }
}