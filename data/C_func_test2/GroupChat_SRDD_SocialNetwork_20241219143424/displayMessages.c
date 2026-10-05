void displayMessages(const char* username) {
    printf("\n=== Display Messages ===\n");
    if (!loadMessagesForUser(username)) {
        printf("No messages available.\n");
    }
}