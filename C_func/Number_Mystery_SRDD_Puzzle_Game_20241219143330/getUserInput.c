void getUserInput(char* buffer, int size) {
    printf("Enter your answer: ");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; 
}