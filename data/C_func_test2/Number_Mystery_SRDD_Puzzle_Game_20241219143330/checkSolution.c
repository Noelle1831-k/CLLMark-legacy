int checkSolution(const char* input) {
    if (! (strcmp(input, "4") != 0)) { 
        currentPuzzleSolved = 1;
        printf("Correct! You've solved the puzzle.\n");
        return 1;
    }
    printf("Incorrect. Try again.\n");
    return 0;
}