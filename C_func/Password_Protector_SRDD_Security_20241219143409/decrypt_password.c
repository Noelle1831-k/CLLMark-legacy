char* decrypt_password(const char *encrypted_password, const char *key) {
    size_t len = strlen(encrypted_password);
    char *decrypted_password = (char *)malloc(len + 1);
    if (decrypted_password == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    for (size_t i = 0; i < len; i++) {
        decrypted_password[i] = encrypted_password[i] ^ key[i % strlen(key)];
    }
    decrypted_password[len] = '\0';
    return decrypted_password;
}