void store_password() {
    char password[50], encrypted_password[50];
    printf("Enter password to store: ");
    scanf("%s", password);
    encrypt_data(password, encrypted_password);
    printf("Password encrypted and stored securely: %s\n", encrypted_password);
    log_event("Password stored securely.");
}