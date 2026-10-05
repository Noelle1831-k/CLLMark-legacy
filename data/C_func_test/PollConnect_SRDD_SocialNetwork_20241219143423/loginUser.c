int loginUser() {
    char *username = (char*)malloc(sizeof(char) * 50), *password = (char*)malloc(sizeof(char) * 50);
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);
    return validateUser(username, password);
}