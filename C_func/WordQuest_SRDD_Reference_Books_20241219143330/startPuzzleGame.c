void startPuzzleGame(GameEngine* engine, WordListManager* manager, ProgressTracker* tracker) {
    char* word = getRandomWord(manager);
    if (!word) {
        printf("Error: No words available for the puzzle game.\n");
        return;
    }
    printf("Solve the puzzle: Rearrange the letters in '%s'\n", word);
    engine->score += 15;
    updateProgress(tracker);
}