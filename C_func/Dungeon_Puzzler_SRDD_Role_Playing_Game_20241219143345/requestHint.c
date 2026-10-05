void requestHint() {
    if (currentPuzzleIndex >= MAX_PUZZLES) {
        printf("No more hints available. You've solved all puzzles!\n");
    } else {
        printf("Here's a hint: %s\n", puzzles[currentPuzzleIndex].hint);
    }
}