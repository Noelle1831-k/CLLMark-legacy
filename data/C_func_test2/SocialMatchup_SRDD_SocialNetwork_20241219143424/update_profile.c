void update_profile() {
    char name[50];
    printf("Enter your name to update profile: ");
    scanf(" %[^\n]%*c", name);
    User* user = find_user_by_name(name);
    if (user == NULL) {
        printf("User not found.\n");
        return;
    }
    printf("Updating profile for %s\n", name);
    printf("Enter new skills (comma-separated): ");
    scanf(" %[^\n]%*c", user->skills);
    printf("Enter new interests (comma-separated): ");
    scanf(" %[^\n]%*c", user->interests);
    printf("Profile updated successfully!\n");
}