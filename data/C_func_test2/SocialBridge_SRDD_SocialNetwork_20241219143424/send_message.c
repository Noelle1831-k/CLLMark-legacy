void send_message() {
    char *receiver = (char*)malloc(sizeof(char) * 50), *content = (char*)malloc(sizeof(char) * 256);

    printf("Enter receiver's email: ");
    scanf("%s", receiver);
    printf("Enter your message: ");
    scanf(" %[^\n]s", content);
    printf("Message sent to %s: %s\n", receiver, content);
}