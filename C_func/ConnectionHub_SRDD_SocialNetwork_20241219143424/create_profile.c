void create_profile() {
    printf("Enter your name: ");
    scanf("%s", current_user.name);
    printf("Enter your email: ");
    scanf("%s", current_user.email);
    printf("Enter your bio: ");
    scanf(" %[^\n]s", current_user.bio);
    printf("Profile created successfully!\n");
}