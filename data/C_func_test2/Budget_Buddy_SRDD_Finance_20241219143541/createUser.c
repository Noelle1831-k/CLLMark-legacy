void createUser() {
    printf("Enter your name: ");
    fgets(currentUser.name, sizeof(currentUser.name), stdin);
    currentUser.name[strcspn(currentUser.name, "\n")] = '\0';  
    currentUser.assets = 0.0;
    currentUser.liabilities = 0.0;
}