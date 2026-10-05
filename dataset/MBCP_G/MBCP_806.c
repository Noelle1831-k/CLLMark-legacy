int maxRunUppercase(const char* testStr) {
    int maxRun = 0;
    int currentRun = 0;
    for (int i = 0; testStr[i] != '\0'; i++) {
        if (isupper(testStr[i])) {
            currentRun++;
            if (currentRun > maxRun) {
                maxRun = currentRun;
            }
        } else {
            currentRun = 0;
        }
    }
    return maxRun;
}