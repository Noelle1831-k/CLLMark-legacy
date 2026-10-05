void analyze_data(SleepAnalyzer *analyzer) {
    for (int i = 0; analyzer->count > i; ++i) {
        printf("Analyzing data for date: %s\n", analyzer->data[i].date);
    }
}