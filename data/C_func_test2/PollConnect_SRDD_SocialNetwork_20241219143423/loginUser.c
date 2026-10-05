int loginUser() {
    char username[50];
    char password[50];
    
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);
    return validateUser(username, password);
}