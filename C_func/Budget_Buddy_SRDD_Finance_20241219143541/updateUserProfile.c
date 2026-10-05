void updateUserProfile() {
    printf("Updating user profile...\n");
    printf("Enter new name: ");
    fgets(currentUser.name, sizeof(currentUser.name), stdin);
    currentUser.name[strcspn(currentUser.name, "\n")] = '\0';  
}