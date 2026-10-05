void handleUserLogin() {
    char username[50], password[50];
    printf("\n=== User Login ===\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    if (loginUser(username, password)) {
        printf("Login successful! Welcome, %s\n", username);
        handleGroupChatOptions(username);
    } else {
        printf("Invalid username or password.\n");
    }
}