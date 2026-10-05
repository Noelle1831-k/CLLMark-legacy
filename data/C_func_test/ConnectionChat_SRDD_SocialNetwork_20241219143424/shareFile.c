void shareFile() {
    char *fileName = (char*)malloc(sizeof(char) * 100);
    printf("Enter file name to share: ");
    fgets(fileName, 100, stdin);
    strtok(fileName, "\n");
    printf("File '%s' shared successfully.\n", fileName);
}