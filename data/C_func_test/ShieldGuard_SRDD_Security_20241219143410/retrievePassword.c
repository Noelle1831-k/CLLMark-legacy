void retrievePassword() {
    char *encrypted = (char*)malloc(sizeof(char) * 100), *decrypted = (char*)malloc(sizeof(char) * 100);

    printf("Enter encrypted password to retrieve: ");
    scanf("%s", encrypted);
    decryptPassword(encrypted, decrypted);
    printf("Retrieved Password: %s\n", decrypted);
}