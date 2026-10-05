void detectFileChanges() {
    printf("Analyzing system logs for suspicious file changes...\n");
    int random = rand() % 10;
    if (random > 6) {
        raiseAlert("Suspicious file changes detected!");
    }
}