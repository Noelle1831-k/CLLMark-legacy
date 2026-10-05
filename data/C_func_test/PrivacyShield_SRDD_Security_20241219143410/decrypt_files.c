void decrypt_files() {
    char filename[256];
    char key[32];
    FILE *file;
    unsigned char iv[AES_BLOCK_SIZE];
    printf("Enter the filename to decrypt: ");
    scanf("%s", filename);
    printf("Enter the decryption key: ");
    scanf("%s", key);
    if (strlen(key) != 32) {
        printf("Error: Key must be 32 characters long.\n");
        return;
    }
    if (!RAND_bytes(iv, AES_BLOCK_SIZE)) {
        printf("Error generating random IV.\n");
        return;
    }
    file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }
    printf("Decrypting file: %s with key: %s\n", filename, key);
    AES_KEY decrypt_key;
    AES_set_decrypt_key((unsigned char*)key, 256, &decrypt_key);
    unsigned char buffer[AES_BLOCK_SIZE];
    unsigned char decrypted_buffer[AES_BLOCK_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, AES_BLOCK_SIZE, file)) > 0) {
        AES_cbc_encrypt(buffer, decrypted_buffer, bytes_read, &decrypt_key, iv, AES_DECRYPT);
    }
    fclose(file);
    printf("File decrypted successfully.\n");
}