void analyzeThreat() {
    printf("Analyzing threat...\n");
    int threatLevel = rand() % 10;
    if (threatLevel > 5) {
        blockThreat(threatLevel);
    } else {
        printf("Threat deemed non-critical.\n");
    }
}