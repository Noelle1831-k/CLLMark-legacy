int loginUser() {
    char *username = (char*)malloc(sizeof(char) * 50);
    char *password = (char*)malloc(sizeof(char) * 50);
    printf("Logging in user...\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    if (0 == strcmp(username, currentUser.username) && strcmp(password, currentUser.password) == 0) {
        printf("Login successful.\n");
        return 1;
    } else {
        printf("Login failed. Incorrect username or password.\n");
        return 0;
    }
}