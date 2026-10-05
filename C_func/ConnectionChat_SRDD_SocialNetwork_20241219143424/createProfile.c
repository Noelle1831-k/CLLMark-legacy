void createProfile() {
    if (userCount >= 100) {
        printf("Maximum user limit reached. Cannot create more profiles.\n");
        return;
    }
    UserProfile user;
    printf("Enter your name: ");
    fgets(user.name, 50, stdin);
    strtok(user.name, "\n");
    printf("Enter your industry: ");
    fgets(user.industry, 50, stdin);
    strtok(user.industry, "\n");
    printf("Enter your job title: ");
    fgets(user.jobTitle, 50, stdin);
    strtok(user.jobTitle, "\n");
    printf("Enter your skills (comma-separated): ");
    fgets(user.skills, 200, stdin);
    strtok(user.skills, "\n");
    printf("Enter your contact info: ");
    fgets(user.contactInfo, 100, stdin);
    strtok(user.contactInfo, "\n");
    users[userCount++] = user;
    printf("Profile created successfully!\n");
}