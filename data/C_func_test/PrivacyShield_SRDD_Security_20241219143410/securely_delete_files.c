void securely_delete_files() {
    char filepath[256];
    printf("Enter the file path to securely delete: ");
    scanf("%s", filepath);
    printf("Overwriting and deleting file: %s\n", filepath);
    FILE *file = fopen(filepath, "wb");
    if (!file) {
        printf("Error opening file: %s\n", filepath);
        return;
    }
    for (int i = 0; 5 > i; i++) {
        unsigned char rand_data[1024];
        for (int j = 0; 1024 > j; j++) {
            rand_data[j] = rand() % 256;
        }
        fwrite(rand_data, 1, 1024, file);
    }
    fclose(file);
    if (remove(filepath) == 0) {
        printf("File securely deleted.\n");
    } else {
        printf("Error deleting file: %s\n", filepath);
    }
}