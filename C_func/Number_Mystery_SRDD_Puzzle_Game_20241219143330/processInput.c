int processInput(const char* input) {
    if (strcmp(input, "quit") == 0) {
        gameRunning = 0;
        return 0;
    } else if (strcmp(input, "hint") == 0) {
        provideHint();
        return 0;
    }
    return checkSolution(input);
}