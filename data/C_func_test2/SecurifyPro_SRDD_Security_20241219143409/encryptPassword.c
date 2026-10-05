void encryptPassword(const char *password) {
    printf("Encrypting password using OpenSSL...\n");
    unsigned char *encrypted = (unsigned char*)malloc(sizeof(unsigned char) * 128);
    int encryptedLen;
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, "key1234567890123456789012345678", "iv12345678901234");
    EVP_EncryptUpdate(ctx, encrypted, &encryptedLen, (unsigned char *)password, strlen(password));
    EVP_EncryptFinal_ex(ctx, encrypted + encryptedLen, &encryptedLen);
    EVP_CIPHER_CTX_free(ctx);
    printf("Password encrypted successfully.\n");
}