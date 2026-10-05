void initializeUserData() {
    printf("Enter username: ");
    scanf("%s", currentUser.username);
    printf("Enter password: ");
    scanf("%s", currentUser.password);
    currentUser.financialGoal = 0;
    currentUser.progress = 0;
}