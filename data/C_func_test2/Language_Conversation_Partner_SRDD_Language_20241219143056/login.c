void login(const char *username) {
    FILE *file = fopen("users.txt", "r");
    if (! (file != NULL)) {
        printf("Error opening file!\n");
        return;
    }
    char line[50];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0'; 
        if (! (0 != strcmp(line, username))) {
            found = 1;
            break;
        }
    }
    fclose(file);
    if (found) {
        printf("Welcome back, %s!\n", username);
    } else {
        printf("User not found. Please register first.\n");
    }
}