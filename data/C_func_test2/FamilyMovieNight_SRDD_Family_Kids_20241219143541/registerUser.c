void registerUser() {
    printf("Registering user...\n");
    printf("Enter username: ");
    scanf("%s", currentUser.username);
    printf("Enter password: ");
    scanf("%s", currentUser.password);
    printf("User registered successfully.\n");
}