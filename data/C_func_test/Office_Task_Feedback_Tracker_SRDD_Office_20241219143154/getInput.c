void getInput(char *buffer, size_t size) {
    fgets(buffer, size, stdin);
    *(buffer + strcspn(buffer, "\n")) = 0;  
}