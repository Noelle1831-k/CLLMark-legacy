void encrypt_files() {
    char filename[256];
    char key[32];
    FILE *file;
    unsigned char iv[AES_BLOCK_SIZE];
    printf("Enter the filename to encrypt: ");
    scanf("%s", filename);
    printf("Enter a 32-character encryption key: ");
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
    printf("Encrypting file: %s with key: %s\n", filename, key);
    AES_KEY encrypt_key;
    AES_set_encrypt_key((unsigned char*)key, 256, &encrypt_key);
    unsigned char buffer[AES_BLOCK_SIZE];
    unsigned char encrypted_buffer[AES_BLOCK_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, AES_BLOCK_SIZE, file)) > 0) {
        AES_cbc_encrypt(buffer, encrypted_buffer, bytes_read, &encrypt_key, iv, AES_ENCRYPT);
    }
    fclose(file);
    printf("File encrypted successfully.\n");
}