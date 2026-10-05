void create_user_profile() {
    struct User user;
    printf("Enter name: ");
    scanf("%s", user.name);
    printf("Enter email: ");
    scanf("%s", user.email);
    validate_email(user.email);
    printf("Are you a professional? (1 for Yes, 0 for No): ");
    if (scanf("%d", &user.isProfessional) != 1) {
        printf("Invalid input for professional status. Please try again.\n");
        exit(EXIT_FAILURE);
    }
    store_user(user);
    printf("User profile created successfully.\n");
}