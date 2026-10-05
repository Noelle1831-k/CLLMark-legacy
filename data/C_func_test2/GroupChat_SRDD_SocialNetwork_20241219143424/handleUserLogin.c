void handleUserLogin() {
    char *username = (char*)malloc(sizeof(char) * 50);
    char *password = (char*)malloc(sizeof(char) * 50);
    
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