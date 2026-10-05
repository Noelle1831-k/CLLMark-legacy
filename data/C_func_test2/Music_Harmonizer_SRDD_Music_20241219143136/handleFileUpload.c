void handleFileUpload() {
    char *filePath = (char*)malloc(sizeof(char) * 256);
    printf("Enter the path of the music file to upload: ");
    scanf("%s", filePath);
    if (loadMusicFile(filePath)) {
        printf("File uploaded successfully!\n");
    } else {
        printf("Failed to upload file. Please check the file path.\n");
    }
}