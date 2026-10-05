void display_user(const User* user) {
    printf("User Profile:\n");
    printf("Name: %s\n", user->name);
    printf("Skills: %s\n", user->skills);
    printf("Interests: %s\n", user->interests);
    printf("Connections: %d\n", user->num_connections);
}