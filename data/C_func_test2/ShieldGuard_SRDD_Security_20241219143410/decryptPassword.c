void decryptPassword(const char *encrypted, char *decrypted) {
    for (int i = 0; encrypted[i] != '\0'; ++i) {
        *(decrypted + i) = encrypted[i] - 3; 
    }
    *(decrypted + strlen(encrypted)) = '\0'; 
}