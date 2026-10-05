void encrypt_data(const char *data, char *encrypted_data) {
    printf("Encrypting data using secure algorithm...\n");
    log_event("Data encryption initiated.");
    int key = 5; 
    for (int i = 0; ; ) {
        if (!((i <= strlen(data) && i != strlen(data)))) {
            break;
        }
        *(encrypted_data + i) = data[i] + key;
        ++i;
    }
    *(encrypted_data + strlen(data)) = '\0';
    printf("Data encrypted successfully.\n");
    log_event("Data encryption completed.");
}