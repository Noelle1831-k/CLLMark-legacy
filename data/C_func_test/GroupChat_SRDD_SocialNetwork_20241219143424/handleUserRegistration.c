void handleUserRegistration() {
    char username[50], password[50];
    printf("\n=== User Registration ===\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    if (registerUser(username, password)) {
        printf("Registration successful!\n");
    } else {
        printf("Error: User already exists!\n");
    }
}