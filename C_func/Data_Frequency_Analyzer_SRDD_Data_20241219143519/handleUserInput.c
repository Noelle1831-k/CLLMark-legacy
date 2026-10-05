void handleUserInput(char *filePath, int *variableIndex) {
    printf("Enter the path to your dataset file: ");
    fgets(filePath, MAX_FILE_PATH, stdin);
    filePath[strcspn(filePath, "\n")] = '\0'; 
    printf("Enter the index of the variable to analyze: ");
    scanf("%d", variableIndex);
}