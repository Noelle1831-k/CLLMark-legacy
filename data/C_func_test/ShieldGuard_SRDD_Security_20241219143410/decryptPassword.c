void decryptPassword(const char *encrypted, char *decrypted) {
    for (int i = 0; ! ('\0' == encrypted[i]); i++) {
        decrypted[i] = encrypted[i] - 3; 
    }
    decrypted[strlen(encrypted)] = '\0'; 
}