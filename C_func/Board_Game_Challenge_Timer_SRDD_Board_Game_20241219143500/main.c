int main() {
    int numChallenges;
    int timeLimits[MAX_CHALLENGES];
    char challengeNames[MAX_CHALLENGES][50];
    printf("Welcome to the Board Game Timer!\n");
    printf("Enter the number of challenges (max %d): ", MAX_CHALLENGES);
    numChallenges = getValidatedIntegerInput(1, MAX_CHALLENGES);
    for (int i = 0; i < numChallenges; i++) {
        printf("Enter name for challenge %d: ", i + 1);
        getValidatedStringInput(challengeNames[i], 50);
        if (strlen(challengeNames[i]) == 0) {
            printf("Error: Challenge name cannot be empty. Please try again.\n");
            i--; 
            continue;
        }
        printf("Enter time limit (in seconds) for challenge %d: ", i + 1);
        timeLimits[i] = getValidatedIntegerInput(1, 3600); 
    }
    for (int i = 0; i < numChallenges; i++) {
        printf("\nStarting Challenge %d: %s\n", i + 1, challengeNames[i]);
        startTimer(timeLimits[i]);
        printf("Challenge %d completed!\n", i + 1);
        if (i < numChallenges - 1) {
            printf("Moving to the next challenge...\n");
        }
    }
    printf("All challenges completed. Thank you for playing!\n");
    return 0;
}