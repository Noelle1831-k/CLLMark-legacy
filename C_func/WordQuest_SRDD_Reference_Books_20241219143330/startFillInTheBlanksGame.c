void startFillInTheBlanksGame(GameEngine* engine, WordListManager* manager, ProgressTracker* tracker) {
    char* word = getRandomWord(manager);
    if (!word) {
        printf("Error: No words available for the fill-in-the-blanks game.\n");
        return;
    }
    printf("Fill in the blanks: _ _ %s\n", word + 2);
    engine->score += 20;
    updateProgress(tracker);
}