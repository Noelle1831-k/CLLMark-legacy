void solvePuzzle() {
    if (currentPuzzleIndex >= MAX_PUZZLES) {
        printf("Congratulations! You've solved all puzzles.\n");
        return;
    }
    char *userSolution = (char*)malloc(sizeof(char) * SOLUTION_LENGTH);
    printf("Puzzle: %s\n", puzzles[currentPuzzleIndex].description);
    printf("Enter your solution: ");
    scanf("%s", userSolution);
    if (checkSolution(userSolution)) {
        printf("Correct! Moving to the next puzzle.\n");
        currentPuzzleIndex++;
    } else {
        printf("Incorrect. Try again or request a hint.\n");
    }
}