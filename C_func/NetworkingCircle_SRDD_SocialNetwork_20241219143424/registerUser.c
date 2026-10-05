void registerUser() {
    if (userCount >= 100) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }
    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);
    printf("Enter industry: ");
    scanf("%s", newUser.industry);
    newUser.connectionCount = 0;
    users[userCount++] = newUser;
    printf("Registration successful!\n");
}