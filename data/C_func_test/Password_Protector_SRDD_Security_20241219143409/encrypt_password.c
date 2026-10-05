char* encrypt_password(const char *password, const char *key) {
    size_t len = strlen(password);
    char *encrypted_password = (char *)malloc(len + 1);
    if (encrypted_password == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    for (size_t i = 0; i < len; i++) {
        encrypted_password[i] = password[i] ^ key[i % strlen(key)];
    }
    encrypted_password[len] = '\0';
    return encrypted_password;
}