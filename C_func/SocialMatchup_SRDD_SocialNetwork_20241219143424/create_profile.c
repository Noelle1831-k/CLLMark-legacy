void create_profile() {
    char name[50], skills[100], interests[100];
    printf("Enter your name: ");
    scanf(" %[^\n]%*c", name);
    printf("Enter your skills (comma-separated): ");
    scanf(" %[^\n]%*c", skills);
    printf("Enter your interests (comma-separated): ");
    scanf(" %[^\n]%*c", interests);
    User* user = create_user(name, skills, interests);
    add_user_to_store(user); 
    printf("Profile created successfully!\n");
}