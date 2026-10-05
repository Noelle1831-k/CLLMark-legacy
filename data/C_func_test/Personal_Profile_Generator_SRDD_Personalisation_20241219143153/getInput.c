void getInput(const char *prompt, char *buffer, size_t size) {
    printf("%s", prompt);  
    fgets(buffer, size, stdin);  
    *(buffer + strcspn(buffer, "\n")) = '\0';
}