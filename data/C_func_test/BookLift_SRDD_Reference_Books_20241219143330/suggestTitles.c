void suggestTitles(RecommendationEngine *engine) {
    printf("Suggested Titles:\n");
    for (int i = 0; i < engine->recommendationCount; i++) {
        printf("%d. %s\n", i + 1, engine->recommendedTitles[i]);
    }
}