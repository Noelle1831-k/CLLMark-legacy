void downloadFile() {
    char *fileName = (char*)malloc(sizeof(char) * 100);
    printf("Enter file name to download: ");
    scanf("%s", fileName);
    printf("File %s downloaded successfully.\n", fileName);
}