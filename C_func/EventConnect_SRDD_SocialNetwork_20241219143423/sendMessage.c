void sendMessage() {
    Message message;
    printf("Enter sender username: ");
    scanf("%s", message.sender);
    printf("Enter receiver username: ");
    scanf("%s", message.receiver);
    printf("Enter message content: ");
    scanf(" %[^\n]s", message.content);
    printf("Message sent from %s to %s: %s\n", message.sender, message.receiver, message.content);
}