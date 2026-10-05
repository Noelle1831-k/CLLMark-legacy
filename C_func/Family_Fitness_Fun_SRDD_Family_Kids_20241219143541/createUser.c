void createUser() {
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("User profile created for %s.\n", name);
    userProgress = 0; 
}