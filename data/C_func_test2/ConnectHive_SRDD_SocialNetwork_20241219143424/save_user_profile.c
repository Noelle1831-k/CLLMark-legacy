void save_user_profile(UserProfile profile) {
    FILE *file = fopen("profiles.dat", "ab");
    if (!file) {
        printf("Error: Unable to save profile.\n");
        return;
    }
    fwrite(&profile, sizeof(UserProfile), 1, file);
    fclose(file);
}