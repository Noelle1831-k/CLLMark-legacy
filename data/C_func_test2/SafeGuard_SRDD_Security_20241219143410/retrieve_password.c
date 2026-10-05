void retrieve_password() {
    char *encrypted_password = (char*)malloc(sizeof(char) * 50);
    char *decrypted_password = (char*)malloc(sizeof(char) * 50);
    
    printf("Enter encrypted password to retrieve: ");
    scanf("%s", encrypted_password);
    decrypt_data(encrypted_password, decrypted_password);
    printf("Decrypted password: %s\n", decrypted_password);
    log_event("Password retrieved successfully.");
}