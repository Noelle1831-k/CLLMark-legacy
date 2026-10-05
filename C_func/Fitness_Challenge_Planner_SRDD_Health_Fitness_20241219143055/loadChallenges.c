void loadChallenges() {
    FILE *file = fopen("challenges.dat", "r");
    if (file != NULL) {
        Challenge challenge;
        while (fread(&challenge, sizeof(Challenge), 1, file)) {
            printf("Loaded Challenge: %s\n", challenge.name);
        }
        fclose(file);
    }
}