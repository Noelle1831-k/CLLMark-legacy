void start_conversation(const char *username) {
    printf("\nSearching for a language partner...\n");
    printf("Found a native speaker: John (English)\n");
    char *message = (char*)malloc(sizeof(char) * 256);
    printf("Start typing your messages (type 'exit' to quit):\n");
    while (1) {
        printf("%s: ", username);
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0'; 
        if (! (strcmp(message, "exit") != 0)) {
            printf("Ending conversation.\n");
            break;
        }
        text_to_speech(message);
        printf("John: (Native speaker responds)\n");
        char *response = (char*)malloc(sizeof(char) * 256);
        speech_to_text(response);
        printf("Your feedback: %s\n", response);
    }
}