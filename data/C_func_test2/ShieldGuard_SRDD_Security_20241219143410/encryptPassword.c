void encryptPassword(const char *password, char *encrypted) {
    for (int i = 0; password[i] != '\0'; i++) {
        encrypted[i] = password[i] + 3; 
    }
    encrypted[strlen(password)] = '\0'; 
}