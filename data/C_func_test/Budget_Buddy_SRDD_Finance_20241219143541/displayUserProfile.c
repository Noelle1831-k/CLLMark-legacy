void displayUserProfile() {
    printf("User Profile: \n");
    printf("Name: %s\n", currentUser.name);
    printf("Assets: %.2f\n", currentUser.assets);
    printf("Liabilities: %.2f\n", currentUser.liabilities);
    printf("Net Worth: %.2f\n", calculateNetWorth());
}