void startWordMatchingGame(GameEngine* engine, WordListManager* manager, ProgressTracker* tracker) {
    char* word = getRandomWord(manager);
    if (!word) {
        printf("Error: No words available for the game.\n");
        return;
    }
    printf("Match the word: %s\n", word);
    engine->score += 10;
    updateProgress(tracker);
}