void createGroup(const char* username) {
    char groupName[50];
    printf("\n=== Create Group ===\n");
    printf("Enter group name: ");
    scanf("%s", groupName);
    if (saveGroupToDatabase(groupName, username)) {
        printf("Group '%s' created successfully by %s!\n", groupName, username);
    } else {
        printf("Error: Group creation failed!\n");
    }
}