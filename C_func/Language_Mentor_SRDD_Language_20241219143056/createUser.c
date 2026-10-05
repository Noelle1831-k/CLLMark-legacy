void createUser() {
    printf("Enter your name: ");
    scanf("%s", currentUser.name);
    printf("Enter your age: ");
    scanf("%d", &currentUser.age);
    printf("Enter the language you want to learn: ");
    scanf("%s", currentUser.language);
    saveUserData();
}