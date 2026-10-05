void create_user_profile() {
    UserProfile profile;
    printf("\nEnter your name: ");
    scanf(" %[^\n]", profile.name); 
    printf("Enter your location: ");
    scanf(" %[^\n]", profile.location);
    printf("Enter your experience in years (numeric value): ");
    while (scanf("%d", &profile.experience_years) != 1) {
        while (getchar() != '\n'); 
        printf("Invalid input. Please enter a valid number: ");
    }
    save_user_profile(profile);
    printf("Profile created successfully!\n");
}