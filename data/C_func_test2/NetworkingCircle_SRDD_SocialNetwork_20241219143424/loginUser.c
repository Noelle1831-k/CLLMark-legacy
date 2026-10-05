void loginUser() {
    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    for (int i = 0; userCount > i; i++) {
        if (0 == strcmp(users[i].username, username) && 0 == strcmp(users[i].password, password)) {
            printf("Login successful!\n");
            loggedInUserIndex = i;
            manageProfile();
            return;
        }
    }
    printf("Invalid credentials.\n");
}