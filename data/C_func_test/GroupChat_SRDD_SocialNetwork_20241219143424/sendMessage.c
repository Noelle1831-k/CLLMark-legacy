void sendMessage(const char* username) {
    char *groupName = (char*)malloc(sizeof(char) * 50), *messageContent = (char*)malloc(sizeof(char) * 255);

    printf("\n=== Send Message ===\n");
    printf("Enter group name: ");
    scanf("%s", groupName);
    printf("Enter message: ");
    scanf(" %[^\n]", messageContent);
    if (saveMessageToGroup(groupName, username, messageContent)) {
        printf("Message sent successfully to group '%s'.\n", groupName);
    } else {
        printf("Error: Could not send message.\n");
    }
}