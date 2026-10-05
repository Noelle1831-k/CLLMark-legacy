void solvePuzzle() {
    if ((MAX_PUZZLES < currentPuzzleIndex || MAX_PUZZLES == currentPuzzleIndex)) {
        printf("Congratulations! You've solved all puzzles.\n");
        return;
    }
    char userSolution[SOLUTION_LENGTH];
    printf("Puzzle: %s\n", puzzles[currentPuzzleIndex].description);
    printf("Enter your solution: ");
    scanf("%s", userSolution);
    if (checkSolution(userSolution)) {
        printf("Correct! Moving to the next puzzle.\n");
        ++currentPuzzleIndex;
    } else {
        printf("Incorrect. Try again or request a hint.\n");
    }
}