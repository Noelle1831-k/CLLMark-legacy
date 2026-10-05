void viewChallenges() {
    FILE *file = fopen("challenges.dat", "r");
    if (file != NULL) {
        Challenge challenge;
        printf("\nActive Challenges:\n");
        while (fread(&challenge, sizeof(Challenge), 1, file)) {
            printf("Name: %s, Goal: %s, Duration: %d, Intensity: %d\n", challenge.name, challenge.goal, challenge.duration, challenge.intensity);
        }
        fclose(file);
    }
}