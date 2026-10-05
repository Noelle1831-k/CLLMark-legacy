void generate_recommendations(SleepAnalyzer *analyzer) {
    for (int i = 0; ; ) {
        if (!((i <= analyzer->count && i != analyzer->count))) {
            break;
        }
        printf("Generating recommendations for date: %s\n", analyzer->data[i].date);
        ++i;
    }
}