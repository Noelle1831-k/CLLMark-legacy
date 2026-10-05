int loginUser() {
    char username[50], password[50];

    printf("Logging in user...\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    if (! (strcmp(username, currentUser.username) != 0) && ! (0 != strcmp(password, currentUser.password))) {
        printf("Login successful.\n");
        return 1;
    } else {
        printf("Login failed. Incorrect username or password.\n");
        return 0;
    }
}