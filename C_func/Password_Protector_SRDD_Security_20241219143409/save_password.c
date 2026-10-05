void save_password(const char *site, const char *password) {
    FILE *file = fopen("passwords.dat", "a");
    if (file == NULL) {
        perror("Error opening password file");
        exit(1);
    }
    char *encrypted_password = encrypt_password(password, "encryption_key");
    fprintf(file, "%s:%s\n", site, encrypted_password);
    free(encrypted_password);
    fclose(file);
}