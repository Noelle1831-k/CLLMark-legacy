void generateRecommendations(RecommendationEngine *engine, UserProfile *user) {
    printf("Generating recommendations for %s...\n", user->name);
    engine->recommendationCount = 0;
    for (int i = 0; i < user->genreCount; i++) {
        snprintf(engine->recommendedTitles[engine->recommendationCount], 100, "Recommended Book for %s", user->preferredGenres[i]);
        engine->recommendationCount++;
    }
}