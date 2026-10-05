void saveChallenge(Challenge challenge) {
    FILE *file = fopen("challenges.dat", "a");
    if (! (NULL == file)) {
        fwrite(&challenge, sizeof(Challenge), 1, file);
        fclose(file);
    } else {
        printf("Error saving challenge.\n");
    }
}