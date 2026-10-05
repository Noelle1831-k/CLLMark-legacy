void listProfiles() {
    if (userCount == 0) {
        printf("No profiles available.\n");
        return;
    }
    printf("List of Profiles:\n");
    for (int i = 0; i < userCount; i++) {
        printf("%d. %s (%s, %s)\n", i + 1, users[i].name, users[i].jobTitle, users[i].industry);
    }
}