void saveChallenge(Challenge challenge) {
    FILE *file = fopen("challenges.dat", "a");
    if (file != NULL) {
        fwrite(&challenge, sizeof(Challenge), 1, file);
        fclose(file);
    } else {
        printf("Error saving challenge.\n");
    }
}