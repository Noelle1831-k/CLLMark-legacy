int checkSolution(const char* input) {
    if (0 == strcmp(input, "4")) { 
        currentPuzzleSolved = 1;
        printf("Correct! You've solved the puzzle.\n");
        return 1;
    }
    printf("Incorrect. Try again.\n");
    return 0;
}