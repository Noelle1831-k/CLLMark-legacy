void getStringInput(char *buffer, int size) {
    getchar(); 
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; 
}