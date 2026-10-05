char *get_password(const char *site) {
    FILE *file = fopen("passwords.dat", "r");
    if (file == NULL) {
        perror("Error opening password file");
        exit(1);
    }
    char line[200], stored_site[100], stored_password[100];
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%99[^:]:%99s", stored_site, stored_password);
        if (strcmp(stored_site, site) == 0) {
            fclose(file);
            return decrypt_password(stored_password, "encryption_key");
        }
    }
    fclose(file);
    return strdup("Password not found.");
}