void register_user(const char *username) {
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%s\n", username);
    fclose(file);
    printf("User %s registered successfully!\n", username);
}