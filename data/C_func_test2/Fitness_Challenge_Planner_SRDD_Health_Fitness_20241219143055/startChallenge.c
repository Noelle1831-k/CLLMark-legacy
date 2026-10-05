void startChallenge() {
    char *name = (char*)malloc(sizeof(char) * 100);
    printf("\nEnter the challenge name to start tracking: ");
    getInputString(name, sizeof(name));
    printf("Tracking started for challenge: %s\n", name);
}