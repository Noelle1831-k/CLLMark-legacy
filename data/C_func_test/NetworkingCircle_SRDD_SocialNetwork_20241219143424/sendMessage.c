void sendMessage() {
    if (loggedInUserIndex == -1) {
        printf("No user logged in.\n");
        return;
    }
    char recipient[50];
    char message[256];
    printf("Enter recipient username: ");
    scanf("%s", recipient);
    printf("Enter your message: ");
    scanf(" %[^\n]", message); 
    printf("Message sent to %s: %s\n", recipient, message);
}