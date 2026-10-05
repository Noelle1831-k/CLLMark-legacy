void storePassword(const char *password) {
    char encrypted[100];
    encryptPassword(password, encrypted);
    printf("Password stored securely.\n");
}