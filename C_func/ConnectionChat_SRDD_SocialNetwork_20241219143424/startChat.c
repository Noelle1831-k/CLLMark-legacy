void startChat() {
    char message[200];
    printf("Enter message to send (type 'exit' to quit):\n");
    while (1) {
        printf("You: ");
        fgets(message, 200, stdin);
        strtok(message, "\n");
        if (strcmp(message, "exit") == 0) {
            printf("Exiting chat...\n");
            break;
        }
        printf("Message sent: %s\n", message);
    }
}