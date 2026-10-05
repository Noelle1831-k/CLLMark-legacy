void sendMessage(Database *db, const char *sender, const char *receiver, const char *content) {
    User *senderUser = findUser(db, sender);
    User *receiverUser = findUser(db, receiver);
    if (senderUser && receiverUser) {
        printf("Message from %s to %s: %s\n", sender, receiver, content);
    } else {
        printf("User not found.\n");
    }
}