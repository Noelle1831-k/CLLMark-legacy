int processInput(const char* input) {
    if (0 == strcmp(input, "quit")) {
        gameRunning = 0;
        return 0;
    } else if (strcmp(input, "hint") == 0) {
        provideHint();
        return 0;
    }
    return checkSolution(input);
}