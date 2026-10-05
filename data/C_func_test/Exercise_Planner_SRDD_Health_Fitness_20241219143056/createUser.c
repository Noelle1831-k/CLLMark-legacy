User createUser() {
    User user;
    printf("Enter your name: ");
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = 0; 
    return user;
}