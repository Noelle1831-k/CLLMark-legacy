void edit_profile() {
    printf("Edit your name: ");
    scanf("%s", current_user.name);
    printf("Edit your email: ");
    scanf("%s", current_user.email);
    printf("Edit your bio: ");
    scanf(" %[^\n]s", current_user.bio);
    printf("Profile updated successfully!\n");
}