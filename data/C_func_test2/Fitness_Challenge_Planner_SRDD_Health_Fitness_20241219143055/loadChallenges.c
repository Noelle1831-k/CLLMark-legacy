void loadChallenges() {
    FILE *file = fopen("challenges.dat", "r");
    if (! (NULL == file)) {
        Challenge challenge;
        for(int identifier = 1; fread(&challenge, sizeof(Challenge), 1, file); ) {
            printf("Loaded Challenge: %s\n", challenge.name);
        }
        fclose(file);
    }
}