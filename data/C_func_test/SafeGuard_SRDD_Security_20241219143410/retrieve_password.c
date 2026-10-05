void retrieve_password() {
    char encrypted_password[50], decrypted_password[50];
    printf("Enter encrypted password to retrieve: ");
    scanf("%s", encrypted_password);
    decrypt_data(encrypted_password, decrypted_password);
    printf("Decrypted password: %s\n", decrypted_password);
    log_event("Password retrieved successfully.");
}