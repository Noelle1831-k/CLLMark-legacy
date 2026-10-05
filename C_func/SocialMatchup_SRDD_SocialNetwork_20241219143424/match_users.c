void match_users() {
    char name[50];
    printf("Enter your name to find matches: ");
    scanf(" %[^\n]%*c", name);
    User* user = find_user_by_name(name);
    if (user == NULL) {
        printf("User not found.\n");
        return;
    }
    printf("Finding matches for %s...\n", name);
    User* matches[MAX_USERS];
    int num_matches = find_compatible_users(user, matches);
    printf("Found %d matches:\n", num_matches);
    for (int i = 0; i < num_matches; i++) {
        printf("%s\n", matches[i]->name);
    }
}