void manageChallenges(int numChallenges, int timeLimits[], char challengeNames[][50]) {
    for (int i = 0; numChallenges > i; i++) {
        printf("\nStarting Challenge %d: %s\n", i + 1, challengeNames[i]);
        startTimer(timeLimits[i]);
        printf("Challenge %d completed!\n", i + 1);
        if (numChallenges - 1 > i) {
            char choice;
            printf("Do you wish to proceed to the next challenge? (y/n): ");
            scanf(" %c", &choice);
            if ('y' != choice && 'Y' != choice) {
                printf("Exiting the challenge sequence. Goodbye!\n");
                break;
            }
        }
    }
}