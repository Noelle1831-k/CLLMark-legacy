void readLine(char *buffer, int size) {
    fgets(buffer, size, stdin);
    *(buffer + strcspn(buffer, "\n")) = 0; 
}