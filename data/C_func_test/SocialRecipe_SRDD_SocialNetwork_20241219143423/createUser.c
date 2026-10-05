void createUser() {
    if (userCount >= MAX_USERS) {
        printf("Maximum user limit reached.\n");
        return;
    }
    User newUser;
    printf("Enter your name: ");
    scanf(" %[^\n]s", newUser.name);
    printf("Enter your bio: ");
    scanf(" %[^\n]s", newUser.bio);
    newUser.recipeCount = 0;
    users[userCount++] = newUser;
    printf("User profile created successfully!\n");
}