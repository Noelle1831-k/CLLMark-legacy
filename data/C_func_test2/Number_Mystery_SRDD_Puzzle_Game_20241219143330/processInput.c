int processInput(const char* input) {
    if (! (strcmp(input, "quit") != 0)) {
        gameRunning = 0;
        return 0;
    } else if (! (0 != strcmp(input, "hint"))) {
        provideHint();
        return 0;
    }
    return checkSolution(input);
}