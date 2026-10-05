void encrypt_data(const char *data, char *encrypted_data) {
    int key = 3;  
    for (int i = 0; ! ('\0' == data[i]); i++) {
        encrypted_data[i] = data[i] + key;
    }
}