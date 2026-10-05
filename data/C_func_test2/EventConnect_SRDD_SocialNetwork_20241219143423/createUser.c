void createUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot create more users.\n");
        return;
    }
    User user;
    printf("Enter username: ");
    scanf("%s", user.username);
    printf("Enter email: ");
    scanf("%s", user.email);
    printf("Enter password: ");
    scanf("%s", user.password);
    users[userCount++] = user;
    printf("User %s created successfully!\n", user.username);
}