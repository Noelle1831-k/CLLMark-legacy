void getStringInput(char *buffer, int length) {
    printf("Enter a string (max %d characters): ", length - 1);
    fgets(buffer, length, stdin);
    *(buffer + strcspn(buffer, "\n")) = '\0'; 
}