void retrievePassword() {
    char encrypted[100];
    char decrypted[100];
    printf("Enter encrypted password to retrieve: ");
    scanf("%s", encrypted);
    decryptPassword(encrypted, decrypted);
    printf("Retrieved Password: %s\n", decrypted);
}