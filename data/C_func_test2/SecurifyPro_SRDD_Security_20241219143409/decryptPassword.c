void decryptPassword(const unsigned char *encrypted) {
    printf("Decrypting password using OpenSSL...\n");
    unsigned char *decrypted = (unsigned char*)malloc(sizeof(unsigned char) * 128);
    int decryptedLen;
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, "key1234567890123456789012345678", "iv12345678901234");
    EVP_DecryptUpdate(ctx, decrypted, &decryptedLen, encrypted, strlen((char *)encrypted));
    EVP_DecryptFinal_ex(ctx, decrypted + decryptedLen, &decryptedLen);
    EVP_CIPHER_CTX_free(ctx);
    printf("Password decrypted successfully: %s\n", decrypted);
}