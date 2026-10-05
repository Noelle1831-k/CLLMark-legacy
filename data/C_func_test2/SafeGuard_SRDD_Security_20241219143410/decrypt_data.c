void decrypt_data(const char *encrypted_data, char *decrypted_data) {
    printf("Decrypting data...\n");
    log_event("Data decryption initiated.");
    int key = 5;
    for (int i = 0; i < strlen(encrypted_data); i++) {
        decrypted_data[i] = encrypted_data[i] - key;
    }
    decrypted_data[strlen(encrypted_data)] = '\0';
    printf("Data decrypted successfully.\n");
    log_event("Data decryption completed.");
}