void joinGroup(const char* username) {
    char groupName[50];
    printf("\n=== Join Group ===\n");
    printf("Enter group name: ");
    scanf("%s", groupName);
    if (addUserToGroup(groupName, username)) {
        printf("Successfully joined group '%s'.\n", groupName);
    } else {
        printf("Error: Group does not exist or could not join.\n");
    }
}