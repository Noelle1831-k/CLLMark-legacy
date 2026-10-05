void sendMessage() {
    char message[256];
    printf("Enter message to send: ");
    scanf(" %[^\n]s", message);
    printf("Sending message: %s\n", message);
}