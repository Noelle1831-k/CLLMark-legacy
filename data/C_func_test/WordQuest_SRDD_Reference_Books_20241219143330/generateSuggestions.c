void generateSuggestions(SuggestionEngine* engine, ProgressTracker* tracker) {
    printf("Suggestions for improvement:\n");
    if (tracker->totalScore < 50) {
        printf("- Practice more word matching games.\n");
        printf("- Spend more time on fill-in-the-blanks activities.\n");
    } else {
        printf("- Try advanced puzzles.\n");
        printf("- Explore new word lists to expand your vocabulary.\n");
    }
}