void searchUsers() {
    if (userCount == 0) {
        printf("No profiles available to search.\n");
        return;
    }
    char query[50];
    int found = 0;
    printf("Enter search query (industry/job title/skill): ");
    fgets(query, 50, stdin);
    strtok(query, "\n");
    for (int i = 0; i < userCount; i++) {
        if (strstr(users[i].industry, query) || strstr(users[i].jobTitle, query) || strstr(users[i].skills, query)) {
            printf("Found: %s (%s, %s)\n", users[i].name, users[i].jobTitle, users[i].industry);
            found++;
        }
    }
    if (!found) {
        printf("No users found matching '%s'.\n", query);
    }
}