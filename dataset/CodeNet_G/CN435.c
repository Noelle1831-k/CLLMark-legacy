char* decryptCaesarCipher(char* encryptedText) {
    int i;
    for (i = 0; encryptedText[i] != '\0'; i++) {
        if (encryptedText[i] >= 'D' && encryptedText[i] <= 'Z') {
            encryptedText[i] = encryptedText[i] - 3;
        } else if (encryptedText[i] >= 'A' && encryptedText[i] <= 'C') {
            encryptedText[i] = encryptedText[i] + 23;
        }
    }
    return encryptedText;
}