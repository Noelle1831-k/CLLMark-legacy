void manage_passwords() {
    printf("Managing passwords...\n");
    char password[256];
    printf("Enter a password to store: ");
    scanf("%s", password);
    printf("Password stored successfully.\n");
    printf("Generating a secure password...\n");
    char secure_password[16];
    generate_secure_password(secure_password, 16);
    printf("Generated password: %s\n", secure_password);
}