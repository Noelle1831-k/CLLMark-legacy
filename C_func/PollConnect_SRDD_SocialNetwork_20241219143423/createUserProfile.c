void createUserProfile() {
    User user;
    printf("Enter Username: ");
    scanf("%s", user.username);
    printf("Enter Password: ");
    scanf("%s", user.password);
    printf("Enter Email: ");
    scanf("%s", user.email);
    saveUser(&user);
    printf("Profile created successfully!\n");
}