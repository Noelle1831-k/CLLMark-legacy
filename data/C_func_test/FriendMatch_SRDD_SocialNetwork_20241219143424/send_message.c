void send_message(User *sender, User *receiver, const char *content) {
    if (sender == NULL || receiver == NULL) {
        fprintf(stderr, "Sender or receiver profile is NULL.\n");
        return;
    }
    Message message;
    strncpy(message.sender, sender->name, sizeof(message.sender) - 1);
    message.sender[sizeof(message.sender) - 1] = '\0'; 
    strncpy(message.receiver, receiver->name, sizeof(message.receiver) - 1);
    message.receiver[sizeof(message.receiver) - 1] = '\0'; 
    strncpy(message.content, content, sizeof(message.content) - 1);
    message.content[sizeof(message.content) - 1] = '\0'; 
    printf("Message from %s to %s: %s\n", message.sender, message.receiver, message.content);
}