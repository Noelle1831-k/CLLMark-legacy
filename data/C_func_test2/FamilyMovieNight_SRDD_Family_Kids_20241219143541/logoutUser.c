void logoutUser() {
    printf("Logging out user...\n");
    memset(&currentUser, 0, sizeof(User));
    printf("User logged out successfully.\n");
}